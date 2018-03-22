#include "Grid.h"
#include "noise.h"


void Grid::createGrid(std::vector<glm::vec3> &io_verts, std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals)
{
    glm::vec3 _position;
    // get the 3d grid points
    std::vector<glm::vec3> points = cube.getPoints();
    // reserve space for the values
    m_values.reserve( points.size() );
    // fill in values
//    Noise noise = Noise(m_frequency, m_height, 3);
    noise::module::Perlin noises;

    for( float i = 0; i < points.size(); ++i )
    {
        _position = glm::vec3(points[i].x, points[i].y, points[i].z);
        // creating terrain
        m_values[i] =
        m_values[i] = m_poly->createSphere(_position,10);/*_position.y + noise.getNoise(_position.x,_position.z)+ noise.getNoise(_position.x/2,_position.z/2) + noise.getNoise(_position.x/3,_position.z/3);*/
        /*m_poly->unions(_position.y + noise.getNoise(_position.x,_position.z) + noise.getNoise(_position.x/3,_position.z/3),
                                     m_poly->createSphere(glm::vec3(_position.x,_position.y-3,_position.z-10),5));*/

    }
    cube.MC(points,m_values, io_verts, io_indices, io_normals);
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
