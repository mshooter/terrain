#include "gtest/gtest.h"
#include "MarchingCube.h"

TEST(MarchingCube, set3DGridPoints)
{
    MarchingCube cube = MarchingCube(60,-60,60);
    MarchingCube cubeTest =  MarchingCube(60,-60,60);
    EXPECT_EQ(cube.getPoints(), cubeTest.getPoints());
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(MarchingCube, setNCells)
{
    MarchingCube cube =  MarchingCube(60,-60,60);
    int testCells = 10;
    cube.setNCells(testCells);
    EXPECT_EQ(testCells, cube.getNCells());
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(MarchingCube, setAxisMax)
{
    MarchingCube cube =  MarchingCube(60,-60,60);
    int testMaxAxis = 10;
    cube.setMaxAxis(testMaxAxis);
    EXPECT_EQ(cube.getAxisMax(), testMaxAxis);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(MarchingCube, setAxisMin)
{
    MarchingCube cube = MarchingCube(60,-60,60);
    int testMinAxis = 10;
    cube.setMinAxis(testMinAxis);
    EXPECT_EQ(cube.getAxisMin(), testMinAxis);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(MarchingCube, getPoints)
{
    MarchingCube cube = MarchingCube(60,-60,60);
    MarchingCube test = MarchingCube(60,-60,60);
    EXPECT_EQ(cube.getPoints(), test.getPoints());
}
