#ifndef MARCHINGCUBE_H
#define MARCHINGCUBE_H

#include "vec3.hpp"
#include <vector>
class MarchingCube
{
public:
    MarchingCube();
    ~MarchingCube();
    std::vector<glm::vec3> getPoints();
    std::vector<float> evaluate();
    void polygonize();
    float cone(float x, float y, float z, float r, float h);
private:
    int m_size;
    int m_axisMin;
    int m_axisMax;
    int m_axisRange;
    std::vector<glm::vec3> MC(std::vector<glm::vec3> &_points, std::vector<float> &_values);
    glm::vec3 interpolate(float isolevel, glm::vec3 p1, glm::vec3 p2, float val1, float val2);
};

#endif // MARCHINGCUBE_H
