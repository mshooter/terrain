#include <math.h>
#include <array>
#include <glm/gtx/compatibility.hpp>

#include "MarchingCube.h"
#include "McData.h"

MarchingCube::MarchingCube()
{
    m_size = 200;
    m_axisMin = -10;
    m_axisMax = 10;
    m_axisRange = m_axisMax - m_axisMin;
}
//------------------------------------------------------------------------------------------------------------------------------------------
std::vector<glm::vec3> MarchingCube::getPoints()
{
    glm::vec3 point;
    std::vector<glm::vec3> points;
    points.reserve(m_size * m_size);

    for(int k = 0 ; k < m_size ; ++k)
    {
        for(int j = 0 ; j < m_size; ++j)
        {
            for(int i = 0 ; i < m_size ; ++i)
            {

                point = glm::vec3(static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * i / ( static_cast<float>(m_size) - 1 ),
                                  static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * j / ( static_cast<float>(m_size) - 1 ),
                                  static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * k / ( static_cast<float>(m_size) - 1 ));
                points.push_back( point );
            }
        }
    }
    return points;
}
//------------------------------------------------------------------------------------------------------------------------------------------
void MarchingCube::MC( std::vector<glm::vec3> &_points, std::vector<float> &_values, std::vector<glm::vec3> &io_verts,
                                                  std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals )
{
  io_verts.reserve( m_size * 3);
  std::array<glm::vec3, 12> vList;
  float size = m_size * m_size;

  // store scalar values corresponding to vertices
  std::array<float, 8> values;

  for ( int z = 0; z < m_size - 1; ++z )
  {
    for ( int y = 0; y < m_size - 1; ++y )
    {
      for ( int x = 0; x < m_size - 1; ++x )
      {
          enum POINT_ID { P, PX, PY, PXY, PZ, PXZ, PYZ, PXYZ};
          std::array<int, 8> point_ids;
          point_ids[P]    = x + m_size * y + size * z;
          point_ids[PX]   = point_ids[P] + 1;
          point_ids[PY]   = point_ids[P] + m_size;
          point_ids[PXY]  = point_ids[PY] + 1;
          point_ids[PZ]   = point_ids[P] + size;
          point_ids[PXZ]  = point_ids[PX] + size;
          point_ids[PYZ]  = point_ids[PY] + size;
          point_ids[PXYZ] = point_ids[PXY] + size;

          // store scalar values corresponding to vertices
          for (unsigned int i = 0; i < values.size(); ++i)
              values[i] = _values[point_ids[i]];

        // place a "1" in bit positions corresponding to vertices whose
        // isovalue is less than given constant.
        int isolevel = 0;
        int cubeindex = 0;

        for (unsigned short i = 0; i < 8; ++i)
        {
            if (values[i] < isolevel) cubeindex |= powers[i];
        }

        // bits = 12 bit number, indicates which edges are crossed by the isosurface
        int bits = edgeTable[ cubeindex ];

        // if none are crossed, proceed to next iteration
        if ( bits == 0)
          continue;

        // check which edges are crossed, and estimate the point location
        // using a weighted average of scalar values at edge endpoints.
        // store the vertex in an array for use later.
        float mu = 0.5f;

        for (unsigned short i = 0; i < 12; ++i)
        {
            auto sigBit = 1 << i;
            if (bits & sigBit)
            {
                const auto v1 = edges[i*2];
                const auto v2 = edges[i*2 + 1];
                mu = ( isolevel - values[v1] ) / ( values[v2] - values[v1] );
                vList[i] = (glm::lerp( _points[point_ids[v1]], _points[point_ids[v2]], mu ));
            }
        }

        cubeindex <<= 4;

        for (int i = 0; triTable[ cubeindex + i ] != -1; i += 3)
        {
            GLushort index = triTable[ cubeindex + i ];
            GLushort index1 = triTable[ cubeindex + i + 1 ];
            GLushort index2 = triTable[ cubeindex + i + 2];

            io_verts.insert(io_verts.end(),{ vList[index], vList[index1], vList[index2] });
            io_normals.insert(io_normals.end(),{ vList[index], vList[index1], vList[index2] });

            GLushort size = io_indices.size();
            GLushort size1 = size+1;
            GLushort size2 = size+2;
            io_indices.insert(io_indices.end(), {size, size1, size2});
        }
      }
    }
  }
}
//------------------------------------------------------------------------------------------------------------------------------------------
void MarchingCube::Testeval(std::vector<glm::vec3> &io_verts,
                            std::vector<GLushort> &io_indices, std::vector<glm::vec3> &io_normals)
{
    glm::vec3 _position;
    std::vector<glm::vec3> points = getPoints();
    m_values.reserve( points.size() );

    // fill in values
    for( unsigned int i = 0; i < points.size(); ++i )
    {
        _position = glm::vec3(points[i].x, points[i].y, points[i].z);
        auto _x = points[i].x;
        auto _y = points[i].y;
        auto _z = points[i].z;
        // evaluate function
        m_values[i] = sin(_x) * _x + _y + sin(_z) - 1.0f ;
    }

    MC(points,m_values, io_verts, io_indices, io_normals);
}
