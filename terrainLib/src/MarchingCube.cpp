#include "MarchingCube.h"
#include "McData.h"
#include <math.h>
#include <array>
#include <gtx/compatibility.hpp>

MarchingCube::MarchingCube()
{
    m_size = 200;
    m_axisMin = -10;
    m_axisMax = 10;
    m_axisRange = m_axisMax - m_axisMin;
}

MarchingCube::~MarchingCube()
{

}

std::vector<glm::vec3> MarchingCube::getPoints()
{
    glm::vec3 point;
    std::vector<glm::vec3> points;
    points.reserve(m_size * m_size * m_size);

    for(int k = 0 ; k < m_size ; ++k)
    {
        for(int j = 0 ; j < m_size; ++j)
        {
            for(int i = 0 ; i < m_size ; ++i)
            {
                point.x = static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * i / ( static_cast<float>(m_size) - 1 );
                point.y = static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * j / ( static_cast<float>(m_size) - 1 );
                point.z = static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * k / ( static_cast<float>(m_size) - 1 );

                points.push_back( point );
            }
        }
    }
    return points;
}

std::vector<glm::vec3> MarchingCube::MC(std::vector<glm::vec3> &_points, std::vector<float> &_values)
{
    std::vector<glm::vec3> vertices;
    vertices.reserve(m_size * 3);
    std::array<glm::vec3, 12> vList;
    float size = m_size * m_size;

    // store scalar values corresponding to vertices
    float value[8];
    // index of base point, and also adjacent points on cube
    int p, px, py, pxy, pz, pxz, pyz, pxyz;

    for(int z=0; z<m_size-1; ++z)
    {
        for(int y=0; y< m_size-1; ++y)
        {
            for(int x=0; x<m_size -1; ++x)
            {
                p = x + m_size * y + size * z;
                px = p + 1;
                py = p + m_size;
                pxy  = py + 1;
                pz   = p + size;
                pxz  = px + size;
                pyz  = py + size;
                pxyz = pxy + size;

                // store scalar values corresponding to vertices
                value[0] = _values[ p ];
                value[1] = _values[ px ];
                value[2] = _values[ py ];
                value[3] = _values[ pxy ];
                value[4] = _values[ pz ];
                value[5] = _values[ pxz ];
                value[6] = _values[ pyz ];
                value[7] = _values[ pxyz ];

                // place a "1" in bit positions corresponding to vertices whose
                       // isovalue is less than given constant.
                       int isolevel = 0;
                       int cubeindex = 0;

                       if (value[0] < isolevel) cubeindex |= 1;
                       if (value[1] < isolevel) cubeindex |= 2;
                       if (value[2] < isolevel) cubeindex |= 8;
                       if (value[3] < isolevel) cubeindex |= 4;
                       if (value[4] < isolevel) cubeindex |= 16;
                       if (value[5] < isolevel) cubeindex |= 32;
                       if (value[6] < isolevel) cubeindex |= 128;
                       if (value[7] < isolevel) cubeindex |= 64;

                       // bits = 12 bit number, indicates which edges are crossed by the isosurface
                       int bits = edgeTable[ cubeindex ];

                       // if none are crossed, proceed to next iteration
                       if ( bits == 0)
                         continue;

                       // check which edges are crossed, and estimate the point location
                       // using a weighted average of scalar values at edge endpoints.
                       // store the vertex in an array for use later.
                       float mu = 0.5f;

                       // bottom of the cube
                       if ( bits & 1 )
                       {
                         mu = ( isolevel - value[0] ) / ( value[1] - value[0] );
                         vList[0] = glm::lerp( _points[p], _points[px], mu );
                         //          vList[0] = lerp( isolevel, _points[p], _points[px], value[0], value[1] );
                       }

                       if ( bits & 2 )
                       {
                         mu = ( isolevel - value[1] ) / ( value[3] - value[1] );
                         vList[1] = glm::lerp( _points[px], _points[pxy], mu );
                         //          vList[1] = lerp( isolevel, _points[px], _points[pxy], value[1], value[2] );
                       }
                       if ( bits & 4 )
                       {
                         mu = ( isolevel - value[2] ) / ( value[3] - value[2] );
                         vList[2] = glm::lerp( _points[py], _points[pxy], mu );
                         //          vList[2] = lerp( isolevel, _points[py], _points[pxy], value[2], value[3] );
                       }

                       if ( bits & 8 )
                       {
                         mu = ( isolevel - value[0] ) / ( value[2] - value[0] );
                         vList[3] = glm::lerp( _points[p], _points[py], mu );
                         //          vList[3] = lerp( isolevel, _points[p], _points[py], value[3], value[4] );
                       }

                       // top of the cube
                       if ( bits & 16 )
                       {
                         mu = ( isolevel - value[4] ) / ( value[5] - value[4] );
                         vList[4] = glm::lerp( _points[pz], _points[pxz], mu );
                         //          vList[4] = lerp( isolevel, _points[pz], _points[pxz], value[4], value[5] );
                       }

                       if ( bits & 32 )
                       {
                         mu = ( isolevel - value[5] ) / ( value[7] - value[5] );
                         vList[5] = glm::lerp( _points[pxz], _points[pxyz], mu );
                         //          vList[5] = lerp( isolevel, _points[pxz], _points[pxyz], value[5], value[6] );
                       }

                       if ( bits & 64 )
                       {
                         mu = ( isolevel - value[6] ) / ( value[7] - value[6] );
                         vList[6] = glm::lerp( _points[pyz], _points[pxyz], mu );
                         //          vList[6] = lerp( isolevel, _points[pyz], _points[pxyz], value[6], value[7] );
                       }

                       if ( bits & 128 )
                       {
                         mu = ( isolevel - value[4] ) / ( value[6] - value[4] );
                         vList[7] = glm::lerp( _points[pz], _points[pyz], mu );
                         //          vList[7] = lerp( isolevel, _points[pz], _points[pyz], value[7], value[4] );
                       }

                       // vertical lines of the cube
                       if ( bits & 256 )
                       {
                         mu = ( isolevel - value[0] ) / ( value[4] - value[0] );
                         vList[8] = glm::lerp( _points[p], _points[pz], mu );
                         //          vList[8] = lerp( isolevel, _points[p], _points[pz], value[0], value[4] );
                       }

                       if ( bits & 512 )
                       {
                         mu = ( isolevel - value[1] ) / ( value[5] - value[1] );
                         vList[9] = glm::lerp( _points[px], _points[pxz], mu );
                         //          vList[9] = lerp( isolevel, _points[px], _points[pxz], value[1], value[5] );
                       }

                       if ( bits & 1024 )
                       {
                         mu = ( isolevel - value[3] ) / ( value[7] - value[3] );
                         vList[10] = glm::lerp( _points[pxy], _points[pxyz], mu );
                         //          vList[10] = lerp( isolevel, _points[pxy], _points[pxyz], value[2], value[6] );
                       }

                       if ( bits & 2048 )
                       {
                         mu = ( isolevel - value[2] ) / ( value[6] - value[2] );
                         vList[11] = glm::lerp( _points[py], _points[pyz], mu );
                         //          vList[11] = lerp( isolevel, _points[py], _points[pyz], value[3], value[7] );
                       }
                       int i = 0;
                       cubeindex <<= 4;

                       while ( triTable[ cubeindex + i ] != -1 )
                       {
                         int index = triTable[ cubeindex + i ];
                         int index1 = triTable[ cubeindex + i + 1 ];
                         int index2 = triTable[ cubeindex + i + 2];

                         vertices.push_back( vList[ index ] );
                         vertices.push_back( vList[ index1 ] );
                         vertices.push_back( vList[ index2 ] );

                         i += 3;
                       }
                     }
                   }
                 }

                 return vertices;
}

std::vector<float> MarchingCube::evaluate()
{
    float x, y, z;
    std::vector<glm::vec3> points = this->getPoints();
    std::vector<float> values;
    values.reserve( points.size() );

    for( unsigned int i = 0; i < points.size(); ++i )
     {
       x = points[i].x;
       y = points[i].y;
       z = points[i].z;

    //        values[i] = x*x + y*y + z*z - 1;
        values[i] = std::min(std::min( -x * x, -y * y), -z * z ) + 1; // cone(x,y,z,0.5f, 1);
      }

      std::vector<float> p;
      std::vector<glm::vec3> MC = this->marchingCube( points, values );
      p.reserve( MC.size() * 3 );
      for ( auto &a : MC )
      {
        p.push_back(a.x);
        p.push_back(a.y);
        p.push_back(a.z);
      }

      return p;
}

glm::vec3 MarchingCube::interpolate(float isolevel, glm::vec3 p1, glm::vec3 p2, float val1, float val2)
{
    float mu;
    glm::vec3 p;
    if(std::abs(isolevel-val1) < 0.00001)
        return(p1);
    if(std::abs(isolevel-val2) < 0.00001)
        return(p2);
    if(std::abs(val1-val2) < 0.00001)
        return(p1);
    mu = (isolevel - val1) / (val2 - val1);
    p.x = p1.x + mu * (p2.x - p1.x);
    p.y = p1.y + mu * (p2.y - p1.y);
    p.z = p1.z + mu * (p2.z - p1.z);

    return p;

}

float MarchingCube::cone(float x, float y, float z, float r, float h)
{
    return sqrt(x*x + y*y + z*z) - 1.0;
}
