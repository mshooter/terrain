#ifndef MESH_H
#define MESH_H

//-------------------------------------------------------------------------------------------------------
/// @author Moira Shooter
/// Modified from :-
/// Jack Diver (08/03/2018). OpenGLTemplate
/// @note changed the class to demo the terrain Library
/// @file Mesh.h
/// @brief Creates a mesh
/// @version
/// @date last revision 24 March 2018
/// \todo
//-------------------------------------------------------------------------------------------------------

#include <QOpenGLFunctions>
#include <vector>
#include <string>
#include "MeshVBO.h"
#include "vec3.hpp"
#include "vec2.hpp"
#include "Grid.h"
#include "MarchingCube.h"




class Mesh
{
public:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Virtual default destructor.
  //-----------------------------------------------------------------------------------------------------
  virtual ~Mesh() = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to load a mesh from a file path.
  //-----------------------------------------------------------------------------------------------------
  void loadMyMesh(int _model);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to reset the mesh arrays.
  //-----------------------------------------------------------------------------------------------------
  void reset();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Gets a pointer to the first data element in the indices array for use with openGL buffers.
  /// @return A pointer to the first element in the indices array.
  //-----------------------------------------------------------------------------------------------------
  const GLushort *getIndicesData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Gets a pointer to the first data element in the vertex array for use with openGL buffers.
  /// @return A pointer to the first element in the vertex array.
  //-----------------------------------------------------------------------------------------------------
  const GLfloat* getVertexData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Gets a pointer to the first data element in the normal array for use with openGL buffers.
  /// @return A pointer to the first element in the normal array.
  //-----------------------------------------------------------------------------------------------------
  const GLfloat* getNormalsData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Gets a pointer to the first data element in the UV array for use with openGL buffers.
  /// @return A pointer to the first element in the UV array.
  //-----------------------------------------------------------------------------------------------------
  const GLfloat* getUVsData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Gets a pointer to the first data element in the specified attribute array for use with
  /// openGL buffers.
  /// @return A pointer to the first element in an attribute array.
  //-----------------------------------------------------------------------------------------------------
  const GLfloat* getAttribData(const MeshAttributes::Attribute _attrib) const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to the the amount of face indices.
  /// @return The size of our indices array.
  //-----------------------------------------------------------------------------------------------------
  int getNIndicesData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to the the amount of vertex data elements.
  /// @return The size of our vertex array.
  //-----------------------------------------------------------------------------------------------------
  int getNVertData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to the the amount of normal data elements.
  /// @return The size of our normal array.
  //-----------------------------------------------------------------------------------------------------
  int getNNormData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to the the amount of UV data elements.
  /// @return The size of our UV array.
  //-----------------------------------------------------------------------------------------------------
  int getNUVData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to the the amount of data elements across all arrays.
  /// @return The size of our data arrays combined.
  //-----------------------------------------------------------------------------------------------------
  int getNData() const noexcept;
  //-----------------------------------------------------------------------------------------------------
  /// @brief method that changes the frequency of the terrain (hills)
  //-----------------------------------------------------------------------------------------------------
  void changeFreq(float _terrainFrequency);
  //-----------------------------------------------------------------------------------------------------
  /// @brief method that changes the height of the terrain (amplitude)
  //-----------------------------------------------------------------------------------------------------
  void changeAmplitude(float _amplitude);
  //-----------------------------------------------------------------------------------------------------
  /// @brief method that changes the seed of the terrain
  //-----------------------------------------------------------------------------------------------------
  void changeSeed(int _seed);
  //-----------------------------------------------------------------------------------------------------
  /// @brief method that changes the resolution of the terrain
  //-----------------------------------------------------------------------------------------------------
  void changeResolution(int _resolution);
  void changeOctaves(int _octaves);
  void changePersistence(float _persistence);

protected:
  //-----------------------------------------------------------------------------------------------------
  /// @brief m_vertices contains the vertices
  //-----------------------------------------------------------------------------------------------------
  std::vector<glm::vec3> m_vertices;
  //-----------------------------------------------------------------------------------------------------
  /// @brief m_normals contains the normals
  //-----------------------------------------------------------------------------------------------------
  std::vector<glm::vec3> m_normals;
  //-----------------------------------------------------------------------------------------------------
  /// @brief m_uvs contains the UVs
  //-----------------------------------------------------------------------------------------------------
  std::vector<glm::vec2> m_uvs;
  //-----------------------------------------------------------------------------------------------------
  /// @brief m_indices contains the indices
  //-----------------------------------------------------------------------------------------------------
  std::vector<GLushort> m_indices;
  //-----------------------------------------------------------------------------------------------------
  /// @brief instance of the class Grid
  //-----------------------------------------------------------------------------------------------------
  Grid terrain;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holdes the frequency of the terrain
  //-----------------------------------------------------------------------------------------------------
  float m_terrainFrequency;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holdes the amplitude of the terrain
  //-----------------------------------------------------------------------------------------------------
  float m_terrainAmplitde;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holdes the seed of the terrain
  //-----------------------------------------------------------------------------------------------------
  float m_terrainSeed;
  float m_terrainOctaves;
  float m_terrainPersistence;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holdes the resolution of the terrain
  //-----------------------------------------------------------------------------------------------------
  int m_terrainResolution = 2;




};

#endif // MESH_H
