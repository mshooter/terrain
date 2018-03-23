#include "gtest/gtest.h"
#include "MarchingCube.h"

TEST(MarchingCube, set3DGridPoints)
{
    MarchingCube cube;
    MarchingCube cubeTest;
    EXPECT_EQ(cube.getPoints(), cubeTest.getPoints());
}

TEST(MarchingCube, setNCells)
{
    MarchingCube cube;
    int testCells = 10;
    cube.setNCells(testCells);
    EXPECT_EQ(testCells, cube.getNCells());
}

TEST(MarchingCube, setAxisMax)
{
    MarchingCube cube;
    int testMaxAxis = 10;
    cube.setAxisMax(testMaxAxis);
    EXPECT_EQ(cube.getAxisMax(), testMaxAxis);
}

TEST(MarchingCube, setAxisMin)
{
    MarchingCube cube;
    int testMinAxis = 10;
    cube.setAxisMin(testMinAxis);
    EXPECT_EQ(cube.getAxisMin(), testMinAxis);
}
