#ifndef MESH_H
#define MESH_H

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

  MarchingCube *cube = new MarchingCube();
  Grid *grid = new Grid(100,2,0.4,12,1,1);
  enum MODELS {GRID, OTHER};

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

};

#endif // MESH_H