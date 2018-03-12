#include "MaterialTesselation.h"
#include "Scene.h"
#include "ShaderLib.h"

void MaterialTesselation::init()
{
    update();
}

void MaterialTesselation::update()
{
    auto shaderPtr = m_shaderLib->getShader(m_shaderName);
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
