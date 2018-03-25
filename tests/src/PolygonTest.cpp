#include "gtest/gtest.h"
#include "Polygon.h"
#include "Noise.h"

TEST(Polygon, createCone)
{
    Polygon poly;
    float p = poly.createCone(glm::vec3(2,2,2), 1.0, 1.0);
    EXPECT_EQ(-7,p);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Polygon, createSphere)
{
    Polygon poly;
    float p = poly.createSphere(glm::vec3(3,3,3), 1.0);
    float test = sqrt(3*3 + 3*3 + 3*3) - 1.0;
    EXPECT_EQ(test, p);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Polygon, createPlane)
{
    Polygon poly;
    float p = poly.createPlane(glm::vec3(2,2,2));
    EXPECT_EQ(2, p);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Polygon, unions)
{
    Polygon poly;
    float p = poly.unions(2,1);
    EXPECT_EQ(1, p);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Polygon, difference)
{
    Polygon poly;
    float p = poly.difference(1,2);
    EXPECT_EQ(2, p);
}
//------------------------------------------------------------------------------------------------------------------------------------------
// need to test that later because havent implemented that right
//TEST(Polygon, displacement)
//{
//    Polygon poly;
//    float p = poly.displacement(glm::vec3(2,2,2));

//}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Polygon, createTerrain1)
{
    Polygon poly;
    Noise noise;
    float p = poly.createTerrain1(glm::vec3(2,2,2), noise);
    float testResult = 2 + noise.getNoise(2,2);
    EXPECT_EQ(testResult,p);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Polygon, createTerrain2)
{
    // this test shouldt pass ? why does it pass
    Polygon poly;
    Noise noise;
    float p = poly.createTerrain2(glm::vec3(1,2,3), noise);
    float testResult = 2 + noise.getNoise(1,3) + noise.getNoise(3,2);
    EXPECT_EQ(testResult, p);
}
//------------------------------------------------------------------------------------------------------------------------------------------
TEST(Polygon, createTerrain3)
{
    Polygon poly;
    Noise noise;
    float p = poly.createTerrain3(glm::vec3(1,2,3), noise);
    float testResult = 2 +  noise.getNoise(1,3) + noise.getNoise(3,2) + noise.getNoise(1,2);
    EXPECT_EQ(testResult, p);
}
