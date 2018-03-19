#ifndef GRID_H
#define GRID_H

#include <vector>
#include <vec3.hpp>
#include <QOpenGLFunctions>
#include "Noise.h"

class Grid
{
public:
    // ---------------------------------------------------------
    /// @build default constructor
    // ---------------------------------------------------------
    Grid(){;}
    // ---------------------------------------------------------
    /// @build copy constructor
    // ---------------------------------------------------------
    Grid(float _size, double _persistence, double _frequecy, double _amplitudd, int _octaves, int _randomSeed);
    // ---------------------------------------------------------
    /// @build deconstructor
    // ---------------------------------------------------------
    ~Grid();
    // ---------------------------------------------------------
    /// @build create grid
    // ---------------------------------------------------------
    void createGrid();
    // ---------------------------------------------------------
    /// @build set size of grid
    /// @parm[_in] _size
    // ---------------------------------------------------------
    void setSize(float _size);
    // ---------------------------------------------------------
    /// @build set scale of grid
    /// @parm [_in] _scale
    // ---------------------------------------------------------
    void setScale(float _scale);
    // ---------------------------------------------------------
    /// @build get list of grid vertices
    // ---------------------------------------------------------
    std::vector<glm::vec3> getListOfGridVertices();
    // ---------------------------------------------------------
    /// @build set list of indices
    // ---------------------------------------------------------
    void setListOfIndices();
    // ---------------------------------------------------------
    /// @build get list of indices
    // ---------------------------------------------------------
    std::vector<GLushort> getListOfGridIndices();
    // ---------------------------------------------------------
    /// @build get list normals
    // ---------------------------------------------------------
    std::vector<glm::vec3> getListOfGridNormals();


private:
    // ---------------------------------------------------------
    /// @build size
    // ---------------------------------------------------------
    float m_size;
    // ---------------------------------------------------------
    /// @build list of vertices
    // ---------------------------------------------------------
    std::vector<glm::vec3> m_listOfVertices;
    // ---------------------------------------------------------
    /// @build list of indices
    // ---------------------------------------------------------
    std::vector<GLushort> m_listOfIndices;
    // ---------------------------------------------------------
    /// @build list of normals
    // ---------------------------------------------------------
    std::vector<glm::vec3> m_listOfNormals;

    Noise m_noise;
    double m_persistence;
    double m_frequency;
    double m_amplitude;
    int m_octaves;
    int m_randomseed;


};

#endif // GRID_H

