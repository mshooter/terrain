#ifndef POLYGONIZER_H
#define POLYGONIZER_H

#include <vector>
#include <QOpenGLFunctions>
#include "glm/glm.hpp"
#include "Datatables.h"

class Polygonizer
{
public:
    /// ------------------------------------------------------------------------------------------
    /// @build default constructor
    /// ------------------------------------------------------------------------------------------
    Polygonizer();
    /// ------------------------------------------------------------------------------------------
    /// @build deconstructor
    /// ------------------------------------------------------------------------------------------
    ~Polygonizer();


    // go through each grid cell (cube) you are building a 3D grid
    // for each vertex of every cube check if vertex is inside or outside of surface
    // for each cube you generate an 8 bit index this will help you to see which edge intersects with the mesh
    // the edge table will return a 12 bit number, which will tell which side of the cube intersects.
    // link with the tri table and it will tell which vertices to join
    /// ------------------------------------------------------------------------------------------
    /// @build get vertices, to set vertices for mesh (   std::vector<glm::vec3> m_vertices; )
    /// ------------------------------------------------------------------------------------------
    std::vector<glm::vec3> setVertices();
    /// ------------------------------------------------------------------------------------------
    /// @build get indices, to set indices for mesh (  std::vector<GLushort> m_indices; )
    /// ------------------------------------------------------------------------------------------
    std::vector<GLushort> setIndices();


private:

};

#endif // POLYGONIZER_H
