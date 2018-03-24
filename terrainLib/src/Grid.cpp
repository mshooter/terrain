#include <algorithm>
#include <iostream>
#include "Grid.h"

//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::createGrid(std::vector<glm::vec3> &io_verts, std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals, int _model)
{

    cube = MarchingCube(m_resolution,-m_range,m_range);
    noise.setNoise(m_frequency, m_height ,m_octaves, m_randomSeed, m_persistence);
    // create a vec3 for the functions
    glm::vec3 _position;
    // get the 3d grid points
    std::vector<glm::vec3> points = cube.getPoints();
    // reserve space for the values
    m_values.reserve( points.size());
    // fill in values
    for( float i = 0; i < points.size(); ++i )
    {
        _position = glm::vec3(points[i].x, points[i].y, points[i].z);
        switch(_model)
        {
        case MODEL1 : { m_values[i] = m_poly->createTerrain1(_position, noise); break; }
        case MODEL2 : { m_values[i] = m_poly->createTerrain2(_position, noise); break; }
        case MODEL3 : { m_values[i] = m_poly->createTerrain3(_position, noise); break; }
        case MODEL4 : { m_values[i] = m_poly->createTerrain4(_position, noise, 20, 10); break; }
        case MODEL5 : { m_values[i] = m_poly->createTerrain5(_position, noise); break; }
        }

    }

    cube.MC(points,m_values, io_verts, io_indices, io_normals);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::editTerrain(std::vector<glm::vec3> &io_verts, std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals, glm::vec3 _toolPosition)
{
    cube = MarchingCube(30,-60,60);
    // create a vec3 for the functions
    glm::vec3 _position;
    // get the 3d grid points
    std::vector<glm::vec3> points = cube.getPoints();
    // reserve space for the values
    m_values.reserve( points.size());
    // fill in values
    for( float i = 0; i < points.size(); ++i )
    {
        _position = glm::vec3(points[i].x, points[i].y, points[i].z);


       m_values[i] = m_poly->createSphere(_position + _toolPosition, 10.0f);


    }
    cube.MC(points,m_values,io_verts,io_indices,io_normals);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setResolution(int _resolution)
{
    m_resolution = _resolution;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setRangeAxis(int _range)
{
    m_range = _range;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setFrequency(float _freq)
{
    m_frequency = _freq;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setHeight(float _height)
{
   m_height = _height;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setSeed(int _seed)
{
    m_randomSeed = _seed;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setOctaves(int _octaves)
{
    m_octaves = _octaves;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setPersistence(float _persistence)
{
    m_persistence = _persistence;
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Grid::getFrequency()
{
    return m_frequency;
}
//------------------------------------------------------------------------------------------------------------------------------------------
int Grid::getSeed()
{
    return m_randomSeed;
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Grid::getHeight()
{
    return m_height;
}
