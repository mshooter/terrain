#include "Polygonizer.h"
#include <iostream>
Polygonizer::Polygonizer()
{
    m_gridSize = 50;
}
//---------------------------------------------------------------------------------
std::vector<glm::vec3> Polygonizer::get3DSpacePoints()
{
//    std::vector<glm::vec3> _listOfPoints;
//    // creating a 3D grid with points
//    for(int z = 0 ; z < m_gridSize - 1; ++z)
//    {
//        for(int y = 0 ; y < m_gridSize - 1; ++y)
//        {
//            for(int x = 0 ; x < m_gridSize - 1; ++x)
//            {
//                // insert all the points into a list
//                _listOfPoints.insert(_listOfPoints.end(), {z,y,x});
//            }
//        }
//    }
//    // return all poins in a vector

}

std::vector<float> Polygonizer::evaluatePoints()
{

//    std::vector<float> _listOfFloats;
//    for(unsigned int i = 0 ; i < get3DSpacePoints().size(); ++i)
//    {
//        _listOfFloats.push_back(meshFunction(get3DSpacePoints()[i].x, get3DSpacePoints()[i].y, get3DSpacePoints()[i].z));
//    }
//    return _listOfFloats;

}

//---------------------------------------------------------------------------------
std::vector<glm::vec3> Polygonizer::setVertices()
{

    // return a vector
    // set vector to m_vertices

}
//---------------------------------------------------------------------------------
std::vector<GLushort> Polygonizer::setIndices()
{

    // return vector
    // set vector to m_indices from Mesh

}
//---------------------------------------------------------------------------------
float Polygonizer::meshFunction(float x, float y, float z)
{
    // this will return normally a sphere
    return sqrt(x*x + y*y + z*z) - 10.0f;
}
