#ifndef POLYGON_H
#define POLYGON_H

// ----------------------------------------------------------------------------------------------------------------------------------------
/// @author Moira Shooter
/// @file Polygon.h
/// @brief Creates signed distance field functions, returns floats to create terrains or other "objects"
/// @version
/// @date last revision 25 March 2018
/// \todo
// ----------------------------------------------------------------------------------------------------------------------------------------

#include <math.h>
#include <vec3.hpp>
#include <vector>
#include "Noise.h"


class Polygon
{
public:
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build default constructor
    // ----------------------------------------------------------------------------------------------------------------------------------------
    Polygon() = default;
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build deconstructor
    // ----------------------------------------------------------------------------------------------------------------------------------------
    ~Polygon(){;}
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create a cone
    /// @parm[_in] _pos : position of the cone
    /// @parm[_in] _r : radius of cone
    /// @parm[_in] _h : height of the cone
    /// @return the value that creates a cone
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createCone(glm::vec3 _pos, float _r, float _h);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create a sphere
    /// @parm[_in] _pos : position of the sphere
    /// @parm[_in] _size : size of the sphere
    /// @return value that creates a sphere
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createSphere(glm::vec3 _pos, float _size);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create a cube
    /// @parm[_in] _pos : position of the cube
    /// @parm[_in] _size: size of the cube
    /// @return  a vlue that creates a cube
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createCube(glm::vec3 _pos, float _size);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create a plane
    /// corrupt
    /// @return value that creates a plane
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createPlane(glm::vec3 _pos);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create union between two objects
    /// @parm[_in] _d1 : object1
    /// @parm[_in] _d2 : object2
    /// @return value that creates the union between two meshes
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float unions(float d1, float d2);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create the difference between two objects
    /// @parm[_in] _d1 : object1
    /// @parm[_in] _d2 : object2
    /// @return value that creates the difference between two meshes
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float difference(float d1, float d2);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create displacements
    /// @parm[_in] _pos : position of object
    /// @return the value that creates displacement of an object
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float displacement(glm::vec3 _pos);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create Terrain1
    /// @parm[_in] _pos : position of object
    /// @parm[_in] _noise : variable noise with all it's information
    /// @return value that creates a terrain of type of mountain
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createTerrain1(glm::vec3 _pos,  Noise _noise);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create Terrain2
    /// @parm[_in] _pos : position of object
    /// @parm[_in] _noise : variable noise with all it's information
    /// @return value that creates a terrain of type canyon
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createTerrain2(glm::vec3 _pos, Noise _noise);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create Terrain3
    /// @parm[_in] _pos : position of object
    /// @parm[_in] _noise : variable noise with all it's information
    /// @return value that creates a terrain of type canyon
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createTerrain3(glm::vec3 _pos, Noise _noise);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create Terrain4
    /// @parm[_in] _pos : position of object
    /// @parm[_in] _noise : variable noise with all it's information
    /// @parm[_in] _max : maximum range for the terrain (height)
    /// @parm[_in] _min : minimum range for the terrain (height)
    /// @return value that creates a terrain of type canyon
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createTerrain4(glm::vec3 _pos, Noise _noise, double _max, double _min);
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build method to create Terrain5
    /// @parm[_in] _pos : position of object
    /// @parm[_in] _noise : variable noise with all it's information
    /// @return value that creates a terrain of type islands/sea
    // ----------------------------------------------------------------------------------------------------------------------------------------
    float createTerrain5(glm::vec3 _pos, Noise _noise);

private:



};

#endif // POLYGON_H
