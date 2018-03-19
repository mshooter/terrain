#ifndef MATERIALTESSELATION_H
#define MATERIALTESSELATION_H

#include "Material.h"
#include "vec3.hpp"
class MaterialTesselation : public Material
{
public:
  MaterialTesselation(const std::shared_ptr<Camera> &io_camera, const std::shared_ptr<ShaderLib> &io_shaderLib, std::array<glm::mat4, 3>* io_matrices) :
    Material(io_camera, io_shaderLib, io_matrices)
  {}
  MaterialTesselation(const MaterialTesselation&) = default;
  MaterialTesselation& operator=(const MaterialTesselation&) = default;
  MaterialTesselation(MaterialTesselation&&) = default;
  MaterialTesselation& operator=(MaterialTesselation&&) = default;
  ~MaterialTesselation() override = default;

  virtual void init() override;

  virtual void update() override;

  virtual const char* shaderFileName() const override;

private:
  float m_innerLevel;
  float m_outerLevel;
  glm::vec3 m_ambient;
};

#endif // MATERIALTESSELATION_H
