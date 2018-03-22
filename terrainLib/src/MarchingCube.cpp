#include <math.h>
#include <array>
#include <glm/gtx/compatibility.hpp>

#include "MarchingCube.h"
#include "McData.h"
#include "Noise.h"

MarchingCube::MarchingCube()
{
    // amount of cells
    m_NCells = 50;
    // size of the cube
    m_axisMin = -10;
    m_axisMax = 10;
    m_axisRange = m_axisMax - m_axisMin;
}
//------------------------------------------------------------------------------------------------------------------------------------------
std::vector<glm::vec3> MarchingCube::getPoints()
{
    // points devide space into a 3D grid
    glm::vec3 point;
    std::vector<glm::vec3> points;
    points.reserve(m_NCells * m_NCells * m_NCells);

    for(int k = 0 ; k < m_NCells; ++k)
    {
        for(int j = 0 ; j < m_NCells; ++j)
        {
            for(int i = 0 ; i < m_NCells; ++i)
            {

                point = glm::vec3(static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * i / ( static_cast<float>(m_NCells)  -1),
                                  static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * j / ( static_cast<float>(m_NCells)  -1),
                                  static_cast<float>(m_axisMin) + static_cast<float>(m_axisRange) * k / ( static_cast<float>(m_NCells)  -1));
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
  io_verts.reserve( m_NCells * 3);
  std::array<glm::vec3, 12> vList;
  float size = m_NCells * m_NCells;

  // store scalar values corresponding to vertices
  std::array<float, 8> values;

  for ( int z = 0; z < m_NCells - 1; ++z )
  {
    for ( int y = 0; y < m_NCells - 1; ++y )
    {
      for ( int x = 0; x < m_NCells - 1; ++x )
      {
          enum POINT_ID { P, PX, PY, PXY, PZ, PXZ, PYZ, PXYZ};
          std::array<int, 8> point_ids;
          point_ids[P]    = x + m_NCells * y + size * z;
          point_ids[PX]   = point_ids[P] + 1;
          point_ids[PY]   = point_ids[P] + m_NCells;
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
//            auto edge1 = vList[index1] - vList[index];
//            auto edge2 = vList[index2] - vList[index];

//            io_normals.push_back(glm::normalize(glm::cross(edge1,edge2)));
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
    // get the 3d grid points
    std::vector<glm::vec3> points = getPoints();
    // reserve space for the values
    m_values.reserve( points.size() );
    // create noise
    Noise noise = Noise(1.0f,0.2f,12.0f,1,1);
    //Noise noise = Noise(static_cast<uint32_t>(0.001));
    // fill in values
    for( float i = 0; i < points.size(); ++i )
    {
        _position = glm::vec3(points[i].x, points[i].y, points[i].z);
        auto x = points[i].x;
        auto y = points[i].y;
        auto z = points[i].z;
        // evaluate function
        // m_poly->createSphere(x,y,z,0.5,m_values[i]);
        // generate a cube rectangle
        //m_values[i] = y + noise.getNoise(x,z);
        //m_values[i] = y + noise.get3Dnoise(x/3,y/3,z/3);
        //m_values[i] = y + noise.get3Dnoise(x/4,y/2,z/4);
        //m_values[i] = std::min(x*-x, y*-y) + 1;
        //m_values[i] = std::min(std::min( -x * x, -y * y), -z * z) + 1; // cone(x,y,z,0.5f, 1);
        //m_poly->unions(m_poly->createSphere(x,y,z,0.5),m_poly->createSphere(x+0.6,y,z,0.5), m_values[i]);
        //m_poly->displacement(x,y,z,m_values[i]);
        m_poly->difference(m_poly->createSphere(x,y-2.5f,z,2),y + noise.getNoise(x,z), m_values[i]);
        // Ncells = 50
        //m_values[i] = y+sin(-x);
        //m_values[i] = y + noise.getNoise(x,z);
    }

    MC(points,m_values, io_verts, io_indices, io_normals);
}

