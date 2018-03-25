#include <algorithm>
#include <iostream>
#include "Grid.h"
#include <fstream>
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::createGrid(std::vector<glm::vec3> &io_verts, std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals, int _model)
{

    cube = MarchingCube(m_resolution,-60,60);
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
    m_gridCreated = true;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Grid::setResolution(int _resolution)
{
    m_resolution = _resolution;
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
void Grid::exportToObj(std::vector<glm::vec3> _vertices, std::vector<glm::vec3> _normals, std::vector<GLushort> _indices)
{

    std::ofstream afile;
    afile.open("terrainModel.obj");
    afile<<"g test"<<'\n';
    afile<<'\n';
    for(unsigned int i = 0 ; i < _vertices.size(); ++i)
    {
        afile<<"v "<<_vertices[i].x<<".0"<<" "<<_vertices[i].y<<".0"<<" "<<_vertices[i].z<<".0"<<'\n';
    }
    afile<<'\n';
    for(unsigned int i = 0 ; i < _normals.size(); ++i)
    {
        afile<<"vn "<<_normals[i].x<<".0"<<" "<<_normals[i].y<<".0"<<" "<<_normals[i].z<<".0"<<'\n';
    }
    afile<<'\n';
      for(unsigned int j = 0 ; j < _vertices.size(); j+=3)
      {
          afile<<"f "<<_indices[j]+1<<" "<<_indices[j]+2<<" "<<_indices[j]+3<<'\n';
      }
    afile.close();
    m_fileExported = true;
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
//------------------------------------------------------------------------------------------------------------------------------------------
bool Grid::getFileExported()
{
    return m_fileExported;
}
//------------------------------------------------------------------------------------------------------------------------------------------
bool Grid::getIsGridCreated()
{
    return m_gridCreated;
}
