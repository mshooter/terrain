#ifndef MATERIALTERRAIN_H
#define MATERIALTERRAIN_H

#include "Material.h"
#include "vec3.hpp"

class MaterialTerrain : public Material
{
public:
  MaterialTerrain(
      const std::shared_ptr<Camera> &io_camera,
      const std::shared_ptr<ShaderLib> &io_shaderLib,
      std::array<glm::mat4, 3>* io_matrices,
      const float _ao,
      const float _exposure,
      const float _roughness,
      const float _metallic,
      const int _model
      ) :
    Material(io_camera, io_shaderLib, io_matrices),
    m_ao(_ao),
    m_exposure(_exposure),
    m_roughness(_roughness),
    m_metallic(_metallic),
    m_model(_model)
  {}
  MaterialTerrain(const MaterialTerrain&) = default;
  MaterialTerrain& operator=(const MaterialTerrain&) = default;
  MaterialTerrain(MaterialTerrain&&) = default;
  MaterialTerrain& operator=(MaterialTerrain&&) = default;
  ~MaterialTerrain() override = default;

  virtual void init() override;

  virtual void update() override;

  virtual const char* shaderFileName() const override;


private:
  glm::vec3 m_albedo;
  float m_ao;
  float m_exposure;
  float m_roughness;
  float m_metallic;
  int m_model;

};

#endif // MATERIALTERRAIN_H
