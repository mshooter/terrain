# Terrain Generator

A terrain generator and editor using noise and Marching Cubes Algorithm, included a file exporter, to export the mesh into an .obj file so you can use it in software such as Houdini and Maya. 

## Content
## 1. **[Installation](#installation)**
### 2. **[Dependencies](#dependencies)**
### 3. **[Building and running](#building-and-running)**
## 4. **[User Instructions](#user-instructions)**
## 5. **[Creating the terrain](#creating-the-terrain)**
## 6. **[Limitations](#limitations)**
## 7. **[References](#references)**
-------------------------------------------------------------
## **Installation**
### **Dependencies** 
* C++11
* OpenGL 
* GLM 
* Qt5 (used for OpenGL functions)
* gtest
### **Building and running** 
bla
## **User Instructions** 
bla
## **Creating the terrain** 
To create a terrain by using the library you do 
```C++
#include "Grid.h"
//.. 

Grid terrain;
```
To load a terrain you can choose different modes
```c++
terrain.createGrid(vertices, indices, normals, mode);
```
the vertices is a vector<glm::vec3> that holds the vertices, same for normals. 
and for indices it is a vector<GLushort> that holds the indices of the mesh.
Because it is procedurally made you can edit the terrain by changing the frequency, amplitude, seed, octaves and persistence. 

Here is an example. 
```C++
terrain.setFrequency(_frequency);
terrain.setHeight(_height);
terrain.setSeed(_seed);
terrain.setOctaves(_octaves);
terrain.setPersistence(_persistence);
```
In the demo, I have set it to change it with the QtSliders, so it is easier to see a result.
Next you can also change the resolution of the terrain. 
```c++
terrain.setResolution(_resolution);
```
Again, in the demo I have set it to change with the QtSliders. 

I have added a function to export the mesh into an .obj format so you can use it in a sofware such as Houdini or Maya. 
```c++
terrain.exportToObj(vertices, normals, indices);
```
You have to insert the vertices, normals and indices vectors into the function so it knows which vertices, normals and indices you mean. 

In the demo I have added an checkBox so when you are happy with the terrain you have, you check it to export. It may take time if the resolution is high. You have to uncheck it or close the application to get the correct .obj file. 
Then check in the demo directory for a terrainModel.obj file and import it in whatever software you want to use.
## **Limitations** 
You can't edit the terrain manually. In the Polygon class you have functions (signed distance field) that creates spheres, cones and cubes. I have added a union and difference function to add meshes together or take a part of a mesh out from one another. With this you could implement a method to carve out the mesh or modify the mesh by using the union/difference method. 
## **References** 
[1] Paulbourke.net. (2018). Polygonising a scalar field (Marching Cubes). [online] Available at: http://paulbourke.net/geometry/polygonise/ [Accessed 24 Mar. 2018].

[2] Iquilezles.org. (2018). Inigo Quilez :: fractals, computer graphics, mathematics, demoscene and more. [online] Available at: http://iquilezles.org/www/articles/distfunctions/distfunctions.htm [Accessed 24 Mar. 2018].

[3] Cubes, G. (2018). Generating terrain using Marching Cubes. [online] Gamedev.stackexchange.com. Available at: https://gamedev.stackexchange.com/questions/54912/generating-terrain-using-marching-cubes [Accessed 24 Mar. 2018].

[4] target, H. (2018). GPU Gems 3: Procedural Terrain in Unity - A Naive Exploration. [online] Unity Community. Available at: https://forum.unity.com/threads/gpu-gems-3-procedural-terrain-in-unity-a-naive-exploration.260645/ [Accessed 24 Mar. 2018].
