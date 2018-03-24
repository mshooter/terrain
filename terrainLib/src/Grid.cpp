#include <algorithm>
#include <iostream>
#include "Grid.h"

//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::createGrid(std::vector<glm::vec3> &io_verts, std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals, int _model)
{

    glm::vec3 _position;
    // get the 3d grid points
    std::vector<glm::vec3> points = cube.getPoints();
    // reserve space for the values
    m_values.reserve( points.size() );
    // fill in values
    Noise noise(m_frequency, m_height ,m_octaves, m_randomSeed, m_persistence);
    for( float i = 0; i < points.size(); ++i )
    {
        _position = glm::vec3(points[i].x, points[i].y, points[i].z);
        switch(_model)
        {
        case MODEL1 : { m_values[i] = m_poly->createTerrain1(_position, noise); break; }
        case MODEL2 : { m_values[i] = m_poly->createTerrain2(_position, noise); break; }
        case MODEL3 : { m_values[i] = m_poly->createTerrain3(_position, noise); break; }
        }


    }

    cube.MC(points,m_values, io_verts, io_indices, io_normals);
}
void Grid::editTerrain(float &io_value, float _oldPrim, float _addPrim)
{
    io_value = m_poly->unions(_oldPrim, _addPrim);
}

//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setResolution(int _res)
{
    cube.setNCells(_res);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setMinAxis(int _axis)
{
    cube.setAxisMin(_axis);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setMaxAxis(int _axis)
{
    cube.setAxisMax(_axis);
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
