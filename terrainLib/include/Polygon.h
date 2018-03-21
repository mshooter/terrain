#ifndef POLYGON_H
#define POLYGON_H

#include <math.h>
#include <vec3.hpp>
#include <vector>
class Polygon
{
public:
    Polygon(){;}
    ~Polygon(){;}
    float createCone(float _x,
                    float _y,
                    float _z,
                    float _r,
                    float _h
                    );
    float createSphere(float _x,
                      float _y,
                      float _z,
                      float _size);
    void unions(float d1, float d2, float &io_value);
    void difference(float d1, float d2, float &io_value);

    void displacement(float x, float y, float z, float &io_value);

    float createPlane(glm::vec3 _pos);
private:

};

#endif // POLYGON_H
