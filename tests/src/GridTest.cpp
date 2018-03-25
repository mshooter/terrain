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
