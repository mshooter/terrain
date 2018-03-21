#include "Polygon.h"
#include <algorithm>
float Polygon::createCone(float _x,
                         float _y,
                         float _z,
                         float _r,
                         float _h)
{
    return std::min((_y-_h)*(_y - _h) - (_x/_r)*(_x/_r) - (_z/_r)*(_z/_r), -( _y * _y - _h ));
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createSphere(float _x, float _y, float _z, float _size)
{
    return sqrt(_x*_x + _y*_y + _z*_z) - _size;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Polygon::unions(float d1, float d2, float &io_value)
{
    io_value = std::min(d1,d2);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Polygon::difference(float d1, float d2, float &io_value)
{
    io_value = std::max(-d1,d2);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void Polygon::displacement(float x, float y, float z, float &io_value)
{
    float d1 = createCone(x,y,z,0.2,1);
    float d2 =  sin(20*x)*sin(20*y)*sin(20*z);
    io_value = d1+d2;
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createPlane(glm::vec3 _pos)
{
    return _pos.y;
}
