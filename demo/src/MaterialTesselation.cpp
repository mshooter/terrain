#include "MaterialTesselation.h"
#include "Scene.h"
#include "ShaderLib.h"

void MaterialTesselation::init()
{
    auto shaderPtr = m_shaderLib->getCurrentShader();
    shaderPtr->setUniformValue("AmbientMaterial", QVector3D{1,1,1});
    shaderPtr->setUniformValue("DiffuseMaterial",QVector3D{0.8f, 0.0f, 0.0f});
    shaderPtr->setUniformValue("LightPosition",QVector3D{1.0f,1.0f, 1.0f});
    m_innerLevel = 1.0;
    m_outerLevel = 1.0;
    update();
}

void MaterialTesselation::update()
{
    auto shaderPtr = m_shaderLib->getShader(m_shaderName);
    shaderPtr->setUniformValue("TessLevelInner",m_innerLevel);
    shaderPtr->setUniformValue("TessLevelOuter",m_outerLevel);
    // scope using declartion
    {
        using namespace SceneMatrices;
        static constexpr std::array<const char*, 3> shaderUniforms = {{"M", "MVP", "N"}};
        // Send all our matrices to the GPU
        for(const auto matrixID : {MODEL_VIEW, PROJECTION, NORMAL})
        {
            // convert from glm to Qt
            QMatrix4x4 qmat(glm::value_ptr((*m_matrices)[matrixID]));
            // Need to transpose the matrix as they both use different majors
            shaderPtr->setUniformValue(shaderUniforms[matrixID], qmat.transposed());
        }
    }
}

const char* MaterialTesselation::shaderFileName() const
{
    return "shaderPrograms/tesselation.json";
}
