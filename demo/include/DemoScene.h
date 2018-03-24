#ifndef DEMOSCENE_H
#define DEMOSCENE_H

//-------------------------------------------------------------------------------------------------------
/// @author Moira Shooter
/// Modified from :-
/// Jack Diver (08/03/2018). OpenGLTemplate
/// @note changes has been to be compatible to demo the terrain library
//-------------------------------------------------------------------------------------------------------



#include "Scene.h"
#include "MaterialPBR.h"
#include "MaterialPhong.h"
#include "ShaderLib.h"


class DemoScene : public Scene
{
  Q_OBJECT
public:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Constructor for DemoScene.
  /// @param [io] io_camera the camera used to view the scene.
  /// @param [io] io_shaderLib the shader library to store and retrieve our shaders.
  /// @param [io] io_parent the parent window to create the GL context in.
  //-----------------------------------------------------------------------------------------------------
  DemoScene(
      const std::shared_ptr<Camera> &io_camera,
      const std::shared_ptr<ShaderLib> &io_shaderLib,
      QWidget *_parent
      ) :
    Scene(io_camera, _parent),
    m_shaderLib(io_shaderLib)
  {}
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default copy constructor.
  //-----------------------------------------------------------------------------------------------------
  DemoScene(const DemoScene&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default copy assignment operator.
  //-----------------------------------------------------------------------------------------------------
  DemoScene& operator=(const DemoScene&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default move constructor.
  //-----------------------------------------------------------------------------------------------------
  DemoScene(DemoScene&&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default move assignment operator.
  //-----------------------------------------------------------------------------------------------------
  DemoScene& operator=(DemoScene&&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default destructor.
  //-----------------------------------------------------------------------------------------------------
  ~DemoScene() override = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to intialise the scene, must call the base class init.
  //-----------------------------------------------------------------------------------------------------
  virtual void init() override;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to intialise the models, vbo and vao.
  //-----------------------------------------------------------------------------------------------------
  void initGeo();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to create our shader programs, or use exisiting ones if they have been loaded.
  //-----------------------------------------------------------------------------------------------------
  void initMaterials();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Receives and acts on a key event.
  /// @param [io] io_event is the key event that was received.
  //-----------------------------------------------------------------------------------------------------
  virtual void keyPress(QKeyEvent* io_event) override;
  //-----------------------------------------------------------------------------------------------------
  /// @brief calls load mesh
  //-----------------------------------------------------------------------------------------------------
  void generateNewGeometry();


public slots:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to allow rotation of the model to be toggled.
  /// @param [in] _rotating tells the scene whether it should rotate the model or not.
  //-----------------------------------------------------------------------------------------------------
  void rotating(const bool _rotating);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to cycle through the materials and apply them to
  /// the current Mesh.
  //-----------------------------------------------------------------------------------------------------
  void nextMaterial();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to change the frequency of the terrain
  //-----------------------------------------------------------------------------------------------------
  void changeFrequency(int _frequency);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to change the height / amplitude of the terrain
  //-----------------------------------------------------------------------------------------------------
  void changeAmplitude(int _amplitude);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to change the seed (have a different terrain)
  //-----------------------------------------------------------------------------------------------------
  void changeSeed(int _seed);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to change the resolution of the mesh
  //-----------------------------------------------------------------------------------------------------
  void changeResolution(int _resolution);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to change the size of the terrain
  //-----------------------------------------------------------------------------------------------------
  void changeRange(int _range);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to have different functions, different type of terrains
  //-----------------------------------------------------------------------------------------------------
  void changeTerrain(int _model);



private:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to write our mesh data into the vbo.
  //-----------------------------------------------------------------------------------------------------
  void writeMeshAttributes();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to pass attribute pointers to the current shader program.
  //-----------------------------------------------------------------------------------------------------
  void setAttributeBuffers();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Must call the base class function, it then applies our shader and draws the current mesh.
  //-----------------------------------------------------------------------------------------------------
  virtual void renderScene() override;


private:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Holds our test meshes.
  //-----------------------------------------------------------------------------------------------------
  std::array<Mesh, 3> m_meshes;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Wraps up our OpenGL buffers and VAO.
  //-----------------------------------------------------------------------------------------------------
  MeshVBO m_meshVBO;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Vertex array object, default constructed with a pointer to this OpenGL widget,
  /// a dynamic_cast is used due to Scene's multiple inheritence.
  //-----------------------------------------------------------------------------------------------------
  std::unique_ptr<QOpenGLVertexArrayObject> m_vao {
    new QOpenGLVertexArrayObject(dynamic_cast<QObject*>(this))
  };
  //-----------------------------------------------------------------------------------------------------
  /// @brief A pointer to the shader library used by this scene.
  //-----------------------------------------------------------------------------------------------------
  std::shared_ptr<ShaderLib> m_shaderLib;
  //-----------------------------------------------------------------------------------------------------
  /// @brief The materials used in this scene.
  //-----------------------------------------------------------------------------------------------------
  std::vector<std::unique_ptr<Material>> m_materials;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Holds the index of the currently drawn mesh in our array of meshes.
  //-----------------------------------------------------------------------------------------------------
  size_t m_meshIndex = 0;
  //-----------------------------------------------------------------------------------------------------
  /// @brief The current material.
  //-----------------------------------------------------------------------------------------------------
  size_t m_currentMaterial = 0;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable to check if the mesh is rotating
  //-----------------------------------------------------------------------------------------------------
  bool m_rotating = false;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holds the frequency of the terrain
  //-----------------------------------------------------------------------------------------------------
  float m_terrainFrequency = 0;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holds the amplitude of the terrain
  //-----------------------------------------------------------------------------------------------------
  float m_terrainAmplitude = 0;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holds the seed of the terrain
  //-----------------------------------------------------------------------------------------------------
  int m_terrainSeed = 1;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holds the terrain resolution
  //-----------------------------------------------------------------------------------------------------
  int m_terrainResolution = 2;
  //-----------------------------------------------------------------------------------------------------
  /// @brief variable that holds the range of axis of the terrain
  //-----------------------------------------------------------------------------------------------------
  int m_terrainRange = 60;
  //-----------------------------------------------------------------------------------------------------
  /// @brief checks which type of grid we are using
  //-----------------------------------------------------------------------------------------------------
  int m_typeGrid = 0;



};

#endif // DEMOSCENE_H
