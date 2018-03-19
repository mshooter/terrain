#include "Grid.h"


Grid::Grid(float _size, double _persistence, double _frequecy, double _amplitudd, int _octaves, int _randomSeed)
{
    m_size = _size;
    m_persistence = _persistence;
    m_frequency = _frequecy;
    m_amplitude = _amplitudd;
    m_octaves = _octaves;
    m_randomseed = _randomSeed;
}

Grid::~Grid()
{

}

void Grid::setVertices()
{
    m_noise.setNoise(m_persistence,m_frequency,m_amplitude,m_octaves,m_randomseed);

    for(float j = 0 ; j < m_size; ++j)
    {
        for(float i = 0 ; i < m_size; ++i)
        {
            m_listOfVertices.insert(m_listOfVertices.end(), {i ,m_noise.getNoise(i,j), j});
            m_listOfNormals.insert(m_listOfNormals.end(), {i ,m_noise.getNoise(i,j), j });
        }
    }
}

void Grid::setSize(float _size)
{
    m_size = _size;
}


std::vector<glm::vec3> Grid::getListOfGridVertices()
{
    return m_listOfVertices;
}

void Grid::setListOfIndices()
{
    // indices
    // http://www.chadvernon.com/blog/resources/directx9/terrain-generation-with-a-heightmap/
    for(int z = 0 ; z < m_size - 1 ; ++z)
    {
        // even rows moe left to right, odd rows move right to left
        if(z % 2 == 0 )
        {
            // even row
            int x;
            for(x = 0 ; x < m_size; ++x)
            {
                m_listOfIndices.insert(m_listOfIndices.end(), {static_cast<unsigned short>(x + (z * m_size)), static_cast<unsigned short>(x + (z * m_size) + m_size)});
            }
            // insert generate vertex if this isnt last row
            if(z != m_size -2)
            {
                m_listOfIndices.insert(m_listOfIndices.end(), {static_cast<unsigned short>(--x + (z*m_size))});
            }
        }
        else
        {
            // odd row
            short int x;
            for(x = m_size -1 ; x >= 0; --x)
            {
                m_listOfIndices.insert(m_listOfIndices.end(), {static_cast<unsigned short>(x + (z * m_size)), static_cast<unsigned short>(x + (z * m_size) + m_size)});
            }
            // insert degernerate vertex if this isnt the last row
            if(z != m_size -2)
            {
                m_listOfIndices.insert(m_listOfIndices.end(), {static_cast<unsigned short>(++x + (z*m_size))});
            }
        }
    }
}

std::vector<GLushort> Grid::getListOfGridIndices()
{
    return m_listOfIndices;
}

std::vector<glm::vec3> Grid::getListOfGridNormals()
{
    return m_listOfNormals;
}


