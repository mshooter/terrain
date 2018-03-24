#include <math.h>
#include "Mesh.h"

//-----------------------------------------------------------------------------------------------------
void Mesh::loadMyMesh(int _model)
{
    reset();
    terrain.setResolution(m_terrainResolution);
    terrain.setRangeAxis(m_terrainRange);
    terrain.setFrequency(m_terrainFrequency);
    terrain.setHeight(m_terrainAmplitde);
    terrain.setSeed(m_terrainSeed);
    terrain.setOctaves(1);
    terrain.setPersistence(1.0f);
    terrain.createGrid(m_vertices,m_indices,m_normals, _model);

}
// ---------------------------------------------------------
void Mesh::reset()
{
    m_indices.clear();
    m_vertices.clear();
    m_normals.clear();
    m_uvs.clear();
}
// ---------------------------------------------------------
const GLushort *Mesh::getIndicesData() const noexcept
{
    return &m_indices[0];
}
// ---------------------------------------------------------
const GLfloat* Mesh::getVertexData() const noexcept
{
    return &m_vertices[0].x;
}
// ---------------------------------------------------------
const GLfloat* Mesh::getNormalsData() const noexcept
{
    return &m_normals[0].x;
}
// ---------------------------------------------------------
const GLfloat *Mesh::getUVsData() const noexcept
{
    return &m_uvs[0].x;
}
// ---------------------------------------------------------
const GLfloat *Mesh::getAttribData(const MeshAttributes::Attribute _attrib) const noexcept
{
    using namespace MeshAttributes;
    const GLfloat * data = nullptr;
    switch (_attrib)
    {
    case VERTEX: data = getVertexData(); break;
    case NORMAL: data = getNormalsData(); break;
    case UV:     data = getUVsData(); break;
    default: break;
    }
    return data;
}
// ---------------------------------------------------------
int Mesh::getNIndicesData() const noexcept
{
    return static_cast<int>(m_indices.size());
}
// ---------------------------------------------------------
int Mesh::getNVertData() const noexcept
{
    return static_cast<int>(m_vertices.size()) * 3;
}
// ---------------------------------------------------------
int Mesh::getNNormData() const noexcept
{
    return static_cast<int>(m_normals.size()) * 3;
}
// ---------------------------------------------------------
int Mesh::getNUVData() const noexcept
{
    return static_cast<int>(m_uvs.size()) * 2;
}
// ---------------------------------------------------------
int Mesh::getNData() const noexcept
{
    return getNVertData() + getNNormData() + getNUVData();
}
// ---------------------------------------------------------
void Mesh::changeFreq(float _terrainFrequency)
{
    m_terrainFrequency = _terrainFrequency;
}
// ---------------------------------------------------------
void Mesh::changeAmplitude(float _amplitude)
{
    m_terrainAmplitde = _amplitude;
}
// ---------------------------------------------------------
void Mesh::changeSeed(int _seed)
{
    m_terrainSeed = _seed;
}
// ---------------------------------------------------------
void Mesh::changeResolution(int _resolution)
{
    m_terrainResolution = _resolution;
}
// ---------------------------------------------------------
void Mesh::changeRange(int _range)
{
    m_terrainRange = _range;
}

std::vector<glm::vec3> Mesh::getVertices()
{
    return m_vertices;
}
