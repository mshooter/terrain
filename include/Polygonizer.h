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
    /// @build function that divides a 3D space into voxel/points
    /// ------------------------------------------------------------------------------------------
    std::vector<glm::vec3> get3DSpacePoints();
    /// ------------------------------------------------------------------------------------------
    /// @build evaluate if the points or negative or postive (inside or outside the mesh)
    std::vector<float> evaluatePoints();
    /// ------------------------------------------------------------------------------------------
    /// @build get vertices, to set vertices for mesh (   std::vector<glm::vec3> m_vertices; )
    /// ------------------------------------------------------------------------------------------
    std::vector<glm::vec3> setVertices();
    /// ------------------------------------------------------------------------------------------
    /// @build get indices, to set indices for mesh (  std::vector<GLushort> m_indices; )
    /// ------------------------------------------------------------------------------------------
    std::vector<GLushort> setIndices();
    /// ------------------------------------------------------------------------------------------
    /// @build temporary test function returns float, because need to know if it is positive or negative
    /// this will tell if the mesh is in the cube or not
    /// ------------------------------------------------------------------------------------------
    float meshFunction(float x, float y, float z);



private:
    /// ------------------------------------------------------------------------------------------
    /// @brief size of voxel
    /// ------------------------------------------------------------------------------------------
    int m_gridSize;

};

#endif // POLYGONIZER_H
