#ifndef POLYGONIZER_H
#define POLYGONIZER_H

#include <vector>
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

private:

};

#endif // POLYGONIZER_H
