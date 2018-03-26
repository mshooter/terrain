# Terrain Generator

A terrain generator and editor using noise and Marching Cubes Algorithm, included a file exporter, to export the mesh into an .obj file so you can use it in software such as Houdini and Maya. 

## Content
## 1. **[Installation](#installation)**
### 1.1 **[Dependencies](#dependencies)**
### 1.2 **[Building and running](#building-and-running)**
## 2. **[User Instructions](#user-instructions)**
### 2.1 **[Controls](#controls)**
## 3. **[Creating the terrain](#creating-the-terrain)**
## 4. **[Pictures](#pictures)**
### 4.1 **[Export .obj file example](#export-.obj-file-example)**
### 4.2 **[More examples of terrains](#more-examples-of-terrains)**
## 5. **[Tests](#tests)**
## 6. **[Limitations](#limitations)**
## 7. **[Extra Notes](#extra-notes)**
## 8. **[References](#references)**
-------------------------------------------------------------
## **Installation**
### **Dependencies** 
* C++11
* OpenGL 
* GLM 
* Qt5 (used for OpenGL functions)
* gtest
### **Building and running** 
1. Git clone the project : git@github.com:mshooter/terrain.git 
2. Go in the directory called terrain 
3. Use qtcreator to open the project (open buildall.pro)
4. Make sure the shadow build is off and the terminal 
5. As an argument you can set it to -j 
6. Run the program
## **User Instructions** 
### Controls (Demo)
Material : Changes the material of the terrain (mountains, canyon with water, canyon without water and islands)

* Rotating : Rotates if you check the box 
* Exporting : Exports the mesh 
* Frequency : Changes the frequency of the hills
* Amplitude : Changes the height/amplitude of the terrain
* Seed : Changes the seed of the noise/terrain
* Resolution : Changes the resolution of the terrain
* Octaves : Changes the octaves of the terrain
* Persistence : Changes the influence of the octaves of the terrain 

You can zoom in and out with the right mouse click, and with the left mouse click you can set to different views.
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
## **Pictures**
### **Export .obj file example**
![screenshot](https://github.com/mshooter/terrain/blob/master/READMEImages/Houdini_0.png)
![screenshot](https://github.com/mshooter/terrain/blob/master/READMEImages/Houdini_02.png)
### **More examples of terrains**
![alt tag](https://github.com/mshooter/terrain/blob/master/READMEImages/mountain.png)
![screenshot](https://github.com/mshooter/terrain/blob/master/READMEImages/canyon.png)
![screenshot](https://github.com/mshooter/terrain/blob/master/READMEImages/Island.png)
![screenshot](https://github.com/mshooter/terrain/blob/master/READMEImages/Canyon2.png)
![alt tag](https://github.com/mshooter/terrain/blob/master/READMEImages/Caves.png)
## Tests
I wrote tests with googletest. I tested if for example void functions were working or if I had the right value. 
For example I tested if setting the height function of the terrain worked 
```c++
TEST(Grid, setHeight)
{
    Grid terrain;
    float testHeight = 10.0f;
    terrain.setHeight(testHeight);
    EXPECT_EQ(terrain.getHeight(), testHeight);

}
```
## **Limitations** 
You can't edit the terrain manually. In the Polygon class you have functions (signed distance field) that creates spheres, cones and cubes. I have added a union and difference function to add meshes together or take a part of a mesh out from one another. With this you could implement a method to carve out the mesh or modify the mesh by using the union/difference method.
## **Extra Notes** 
For the demo I have used Jack Diver's OpenGLTemplate: https://github.com/nitronoid/OpenGLTemplate. I have modified it to make it function with my library. I have modified a PBR shader, called MaterialTerrain(.cpp), so when the terrain point is on a certain height it would change colour. 
## **References** 
[1] Paulbourke.net. (2018). Polygonising a scalar field (Marching Cubes). [online] Available at: http://paulbourke.net/geometry/polygonise/ [Accessed 24 Mar. 2018].

[2] Iquilezles.org. (2018). Inigo Quilez :: fractals, computer graphics, mathematics, demoscene and more. [online] Available at: http://iquilezles.org/www/articles/distfunctions/distfunctions.htm [Accessed 24 Mar. 2018].

[3] Cubes, G. (2018). Generating terrain using Marching Cubes. [online] Gamedev.stackexchange.com. Available at: https://gamedev.stackexchange.com/questions/54912/generating-terrain-using-marching-cubes [Accessed 24 Mar. 2018].

[4] target, H. (2018). GPU Gems 3: Procedural Terrain in Unity - A Naive Exploration. [online] Unity Community. Available at: https://forum.unity.com/threads/gpu-gems-3-procedural-terrain-in-unity-a-naive-exploration.260645/ [Accessed 24 Mar. 2018].

