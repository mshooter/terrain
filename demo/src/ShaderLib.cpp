#include "ShaderLib.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <array>

std::string ShaderLib::loadShaderProg(const QString &_jsonFileName)
{
  auto toStr = [](const auto& val){ return val.toString(); };
  // Read in raw file
  QFile file(_jsonFileName);
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  QByteArray rawData = file.readAll();
  // Parse document
  QJsonDocument doc(QJsonDocument::fromJson(rawData));
  // Get the json object to view
  QJsonObject shaderParts = doc.object();

  // Get a string out from the json
  std::string shaderName = shaderParts["Name"].toString().toStdString();

  enum {VERTEX, FRAGMENT, GEOMETRY, CONTROL, EVALUATION};
  constexpr std::array<const char*, 5> shaderNames = {{"Vertex", "Fragment", "Geometry", "TessellationControl", "TessellationEvaluation"}};
  std::array<QString, 5> shaderPaths;

  for (auto shader : {VERTEX, FRAGMENT, GEOMETRY, CONTROL, EVALUATION})
  {
    auto& name = shaderNames[shader];
    shaderPaths[shader] = shaderParts.contains(name) ? toStr(shaderParts[name]) : "";
  }

  // Load the shader if we haven't already
  if (!m_shaderPrograms.count(shaderName))
    createShader(shaderName, shaderPaths);

  return shaderName;
}

void ShaderLib::createShader(const std::string &_name, const std::array<QString, 5> &_shaderPaths)
{
  QOpenGLShaderProgram *program = new QOpenGLShaderProgram();

  enum {VERTEX, FRAGMENT, GEOMETRY, CONTROL, EVALUATION};
  using shdr = QOpenGLShader;
  constexpr shdr::ShaderType qShaders[] = {shdr::Vertex, shdr::Fragment, shdr::Geometry, shdr::TessellationControl, shdr::TessellationEvaluation};
  for (auto shader : {VERTEX, FRAGMENT, GEOMETRY, CONTROL, EVALUATION})
  {
    auto path = _shaderPaths[shader];
    if (path == "") continue;
    auto stdPath = path.toStdString();
    if (!m_shaderParts.count(stdPath))
    {
      QOpenGLShader* shad = new QOpenGLShader(qShaders[shader]);
      shad->compileSourceFile(path);
      m_shaderParts[stdPath].reset(shad);
    }
    program->addShader(m_shaderParts[stdPath].get());
  }
  program->link();
  m_shaderPrograms[_name].reset(program);
}

void ShaderLib::useShader(const std::string& _name)
{
  m_currentShader = m_shaderPrograms[_name].get();
  m_currentShader->bind();
}

QOpenGLShaderProgram *ShaderLib::getShader(const std::string& _name)
{
  return m_shaderPrograms[_name].get();
}

QOpenGLShaderProgram* ShaderLib::getCurrentShader()
{
  return m_currentShader;
}

