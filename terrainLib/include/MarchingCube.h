#ifndef MARCHINGCUBE_H
#define MARCHINGCUBE_H

#include <QOpenGLFunctions>
#include <vector>
#include "vec3.hpp"
#include "Polygon.h"

class MarchingCube
{
public:
    //------------------------------------------------------------------------------------------------------------------------------------------
    /// @build constructor
    //------------------------------------------------------------------------------------------------------------------------------------------
    MarchingCube();
    //------------------------------------------------------------------------------------------------------------------------------------------
    /// @build deconstructor
    //------------------------------------------------------------------------------------------------------------------------------------------
    ~MarchingCube(){;}
    //------------------------------------------------------------------------------------------------------------------------------------------
    /// @build get points from the 3D grid
    //------------------------------------------------------------------------------------------------------------------------------------------
    std::vector<glm::vec3> getPoints();
    //------------------------------------------------------------------------------------------------------------------------------------------
    /// @build Marching cube algorithm
    //------------------------------------------------------------------------------------------------------------------------------------------
    void MC(std::vector<glm::vec3> &_points,
            std::vector<float> &_values, std::vector<glm::vec3> &io_verts, std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals);
    void setNCells(int _cells);
    void setAxisMin(int _minAxis);
    void setAxisMax(int _maxAxis);

private:
    //------------------------------------------------------------------------------------------------------------------------------------------
    /// @build list of values
    //------------------------------------------------------------------------------------------------------------------------------------------
    std::vector<float> m_values;
    //------------------------------------------------------------------------------------------------------------------------------------------
    /// @build Polygon
    //------------------------------------------------------------------------------------------------------------------------------------------
    Polygon *m_poly;
    //------------------------------------------------------------------------------------------------------------------------------------------
    /// @build amount of cells
    //------------------------------------------------------------------------------------------------------------------------------------------
    int m_NCells;
    //------------------------------------------------------------------------------------------------------------------------------------------
    /// @build range of the size of the cube
    //------------------------------------------------------------------------------------------------------------------------------------------
    int m_axisRange;
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build maxAxis
    // ----------------------------------------------------------------------------------------------------------------------------------------
    int m_axisMax;
    // ----------------------------------------------------------------------------------------------------------------------------------------
    /// @build minAxis
    // ----------------------------------------------------------------------------------------------------------------------------------------
    int m_axisMin;
};

#endif // MARCHINGCUBE_H
