#include <gtest/gtest.h>
#include "Parameters.hpp"

TEST(ParametersTest, ValidParameters)
{
    Parameters p = {16, 98, false, 36.5, 120, 70, 'A'};
    EXPECT_TRUE(p.isValid());
}

TEST(ParametersTest, InvalidRespRate)
{
    Parameters p = {-1, 98, false, 36.5, 120, 70, 'A'};
    EXPECT_FALSE(p.isValid());
    p.respRate = 200;
    EXPECT_FALSE(p.isValid());
}

TEST(ParametersTest, InvalidOxygenSat)
{
    Parameters p = {16, 40, false, 36.5, 120, 70, 'A'};
    EXPECT_FALSE(p.isValid());
    p.oxygenSat = 110;
    EXPECT_FALSE(p.isValid());
}

TEST(ParametersTest, InvalidTemperature)
{
    Parameters p = {16, 98, false, 10, 120, 70, 'A'};
    EXPECT_FALSE(p.isValid());
    p.temperature = 60;
    EXPECT_FALSE(p.isValid());
}

TEST(ParametersTest, InvalidBP)
{
    Parameters p = {16, 98, false, 36.5, -10, 70, 'A'};
    EXPECT_FALSE(p.isValid());
    p.systolicBP = 400;
    EXPECT_FALSE(p.isValid());
}

TEST(ParametersTest, InvalidHeartRate)
{
    Parameters p = {16, 98, false, 36.5, 120, 10, 'A'};
    EXPECT_FALSE(p.isValid());
    p.heartRate = 300;
    EXPECT_FALSE(p.isValid());
}

TEST(ParametersTest, InvalidConsciousness)
{
    Parameters p = {16, 98, false, 36.5, 120, 70, 'X'};
    EXPECT_FALSE(p.isValid());
    p.consciousness = 'a';    // lowercase
    EXPECT_TRUE(p.isValid()); // toupper makes it A
}