#include "gtest/gtest.h"
#include "Grid.h"

TEST(Grid, setFrequency)
{
    Grid terrain;
    float testFrequency = 10.0f;
    terrain.setFrequency(testFrequency);
    EXPECT_EQ(testFrequency,terrain.getFrequency());

}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Grid, setSeed)
{
    Grid terrain;
    int testSeed = 5.0;
    terrain.setSeed(testSeed);
    EXPECT_EQ(terrain.getSeed(), testSeed);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Grid, setHeight)
{
    Grid terrain;
    float testHeight = 10.0f;
    terrain.setHeight(testHeight);
    EXPECT_EQ(terrain.getHeight(), testHeight);

}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Grid, fileExport)
{
    Grid terrain;
    std::vector<glm::vec3> _vertices = {{0,0,0},{0,0,0},{0,0,0}};
    std::vector<glm::vec3> _normals = {{0,0,0},{0,0,0},{0,0,0}};
    std::vector<GLushort> _indices = {1,2,3,4,5,6};
    terrain.exportToObj(_vertices, _normals, _indices);
    EXPECT_TRUE(terrain.getFileExported());
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Grid, createGrid)
{
    Grid terrain;
    std::vector<glm::vec3> _vertices = {{0,0,0},{0,0,0},{0,0,0}};
    std::vector<glm::vec3> _normals = {{0,0,0},{0,0,0},{0,0,0}};
    std::vector<GLushort> _indices = {1,2,3,4,5,6};
    int mode = 0;
    terrain.createGrid(_vertices, _indices, _normals, mode);
    EXPECT_TRUE(terrain.getIsGridCreated());

}
