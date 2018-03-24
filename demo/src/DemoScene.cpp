
#include "DemoScene.h"
#include "MaterialPBR.h"
#include "MaterialTerrain.h"
#include "materialbump.h"
#include <QOpenGLContext>

//-----------------------------------------------------------------------------------------------------
void DemoScene::writeMeshAttributes()
{
  const auto& mesh = m_meshes[m_meshIndex];

  using namespace MeshAttributes;
  for (const auto buff : {VERTEX, UV, NORMAL})
  {
    m_meshVBO.write(mesh.getAttribData(buff), buff);
  }
  m_meshVBO.setIndices(mesh.getIndicesData());
}
//-----------------------------------------------------------------------------------------------------
void DemoScene::setAttributeBuffers()
{
  static constexpr int tupleSize[] = {3,2,3};
  auto prog = m_shaderLib->getCurrentShader();

  using namespace MeshAttributes;
  for (const auto buff : {VERTEX, UV, NORMAL})
  {
    prog->enableAttributeArray(buff);
    prog->setAttributeBuffer(buff, GL_FLOAT, m_meshVBO.offset(buff), tupleSize[buff]);
  }

}
//-----------------------------------------------------------------------------------------------------
void DemoScene::init()
{
  Scene::init();

  initMaterials();
  initGeo();
  // Scope the using declaration
  {
    using namespace SceneMatrices;
    m_matrices[MODEL_VIEW] = glm::translate(m_matrices[MODEL_VIEW], glm::vec3(0.0f, 0.0f, -2.0f));
  }
}
//-----------------------------------------------------------------------------------------------------
void DemoScene::initGeo()
{

    m_meshes[0].loadMyMesh(Grid::MODELS::MODEL2);
    // Create and bind our Vertex Array Object
    m_vao->create();
    m_vao->bind();
    // Create and bind our Vertex Buffer Object
    m_meshVBO.init();

    generateNewGeometry();
}
//-----------------------------------------------------------------------------------------------------
void DemoScene::keyPress(QKeyEvent* io_event)
{
  makeCurrent();
  Scene::keyPress(io_event);
  m_materials[m_currentMaterial]->handleKey(io_event, context());
}
//-----------------------------------------------------------------------------------------------------
void DemoScene::initMaterials()
{

  m_materials.reserve(3);
  m_materials.emplace_back(new MaterialTerrain(m_camera, m_shaderLib, &m_matrices, 1.0f, 1.0f, 1.0f, 1.0f, 0));
  m_materials.emplace_back(new MaterialTerrain(m_camera, m_shaderLib, &m_matrices, 1.0f, 1.0f, 1.0f, 1.0f, 1));
  for (size_t i = 0; i < m_materials.size(); ++i)
  {
    auto& mat = m_materials[i];
    auto name = m_shaderLib->loadShaderProg(mat->shaderFileName());
    mat->setShaderName(name);
    mat->apply();
  }
  m_materials[m_currentMaterial]->apply();
}
//-----------------------------------------------------------------------------------------------------
void DemoScene::rotating( const bool _rotating )
{
  m_rotating = _rotating;
}
//-----------------------------------------------------------------------------------------------------
void DemoScene::generateNewGeometry()
{

  makeCurrent();
  m_meshIndex = 0;
  auto& mesh = m_meshes[m_meshIndex];
  m_meshVBO.reset(
        sizeof(GLushort),
        mesh.getNIndicesData(),
        sizeof(GLfloat),
        mesh.getNVertData(),
        mesh.getNUVData(),
        mesh.getNNormData()
        );
  writeMeshAttributes();
  setAttributeBuffers();
}
//-----------------------------------------------------------------------------------------------------
void DemoScene::nextMaterial()
{
  makeCurrent();
  m_currentMaterial = (m_currentMaterial + 1) % m_materials.size();

  m_materials[m_currentMaterial]->apply();
  setAttributeBuffers();
}
//-----------------------------------------------------------------------------------------------------
void DemoScene::renderScene()
{
  Scene::renderScene();
  // Scope the using declaration
  {
    using namespace SceneMatrices;
    m_matrices[MODEL_VIEW] = glm::rotate(m_matrices[MODEL_VIEW], glm::radians(1.0f * m_rotating), glm::vec3(0.0f, 1.0f, 0.0f));
  }
  m_materials[m_currentMaterial]->update();
  m_meshes[0].changeFreq(m_terrainFrequency);
  m_meshes[0].changeAmplitude(m_terrainAmplitude);
  //_meshes[0].changeSeed(m_terrainSeed, Grid::MODELS::MODEL3);
  m_meshes[0].loadMyMesh(Grid::MODELS::MODEL2);
  m_meshVBO.use();
  glDrawElements(GL_TRIANGLES, m_meshes[m_meshIndex].getNIndicesData(), GL_UNSIGNED_SHORT, nullptr);
  generateNewGeometry();

}
//-----------------------------------------------------------------------------------------------------
void DemoScene::changeFrequency(int _frequency)
{
    m_terrainFrequency = _frequency / 100.0f;
}

void DemoScene::changeAmplitude(int _amplitude)
{
    m_terrainAmplitude = _amplitude;
}

void DemoScene::changeSeed(int _seed)
{
    m_terrainSeed = _seed;
}
