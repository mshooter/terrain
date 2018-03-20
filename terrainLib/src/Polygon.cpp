#include "Polygon.h"

void Polygon::createCone(float _x,
                         float _y,
                         float _z,
                         float _r,
                         float _h,
                         float &io_value)
{
    io_value = std::min((_y-_h)*(_y - _h) - (_x/_r)*(_x/_r) - (_z/_r)*(_z/_r), -( _y * _y - _h ));
}

void Polygon::createSphere(float _x, float _y, float _z, float _size, float &io_value)
{
    io_value = sqrt(_x*_x + _y*_y + _z*_z) - _size;
}
