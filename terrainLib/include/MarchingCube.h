#ifndef MARCHINGCUBE_H
#define MARCHINGCUBE_H

#include <QOpenGLFunctions>
#include <vector>
#include "vec3.hpp"

class MarchingCube
{
public:
    MarchingCube();
    ~MarchingCube(){;}
    std::vector<glm::vec3> getPoints();
    void Testeval(std::vector<glm::vec3> &io_verts, std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals);
    float cone(float _x, float _y, float _z, float _r, float _h);
    void MC(std::vector<glm::vec3> &_points,
            std::vector<float> &_values, std::vector<glm::vec3> &io_verts, std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals);

private:
    std::vector<float> m_values;
    int m_size;
    int m_axisMin;
    int m_axisMax;
    int m_axisRange;

};

#endif // MARCHINGCUBE_H
