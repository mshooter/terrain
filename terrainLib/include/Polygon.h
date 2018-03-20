#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <math.h>

class Polygon
{
public:
    Polygon(){;}
    ~Polygon(){;}
    void createCone(float _x,
                    float _y,
                    float _z,
                    float _r,
                    float _h,
                    float &io_value);
    void createSphere(float _x,
                      float _y,
                      float _z,
                      float _size,
                      float &io_value);
};

#endif // POLYGON_H
