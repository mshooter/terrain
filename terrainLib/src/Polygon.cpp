#include <math.h>
#include "Polygon.h"

//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createCone(glm::vec3 _pos,
                         float _r,
                         float _h)
{
    return std::min((_pos.y-_h)*(_pos.y - _h) - (_pos.x/_r)*(_pos.x/_r) - (_pos.z/_r)*(_pos.z/_r), -( _pos.y * _pos.y - _h ));
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createSphere(glm::vec3 _pos, float _size)
{
    return sqrt(_pos.x*_pos.x + _pos.y*_pos.y + _pos.z*_pos.z) - _size;
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createPlane(glm::vec3 _pos)
{
    return _pos.y;
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createCube(glm::vec3 _pos, float _size)
{
    return std::min(std::min( -_pos.x * _pos.x, -_pos.y * _pos.y), -_pos.z * _pos.z ) + _size;
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::unions(float d1, float d2)
{
    return std::min(d1,d2);
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::difference(float d1, float d2)
{
    return std::max(-d1,d2);
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::displacement(glm::vec3 _pos)
{
    float d1 = createCone(_pos,0.2,1);
    float d2 =  sin(20*_pos.x)*sin(20*_pos.y)*sin(20*_pos.z);
    return d1+d2;
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createTerrain1(glm::vec3 _pos, Noise _noise)
{
    return _noise.getNoise(_pos.x, _pos.z) + _pos.y;
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createTerrain2(glm::vec3 _pos, Noise _noise)
{
    return _pos.y + _noise.getNoise(_pos.x,_pos.z) + _noise.getNoise(_pos.z,_pos.y );
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createTerrain3(glm::vec3 _pos, Noise _noise)
{
    return _pos.y + _noise.getNoise(_pos.x, _pos.z) + _noise.getNoise(_pos.z, _pos.y) + _noise.getNoise(_pos.x, _pos.y);
}
//------------------------------------------------------------------------------------------------------------------------------------------
float Polygon::createTerrain4(glm::vec3 _pos, Noise _noise, double _max, double _min)
{
    return std::min(_max,std::max(_noise.getNoise(_pos.x,_pos.z),-_min)) + _pos.y;
}
