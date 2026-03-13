#include <gtest/gtest.h>
#include "NEWSCalculator.hpp"

TEST(NEWSCalculatorTest, LowRisk)
{
    Parameters p = {16, 98, false, 36.5, 120, 70, 'A'};
    Score s = NEWSCalculator::calculate(p);
    EXPECT_EQ(s.value, 0);
    EXPECT_EQ(s.riskLevel, "Low");
}

TEST(NEWSCalculatorTest, MediumRisk)
{
    Parameters p = {22, 96, true, 37, 105, 95, 'A'};
    Score s = NEWSCalculator::calculate(p);
    EXPECT_EQ(s.value, 6);
    EXPECT_EQ(s.riskLevel, "Medium");
}

TEST(NEWSCalculatorTest, HighRisk)
{
    Parameters p = {30, 85, true, 40, 80, 140, 'V'};
    Score s = NEWSCalculator::calculate(p);
    EXPECT_GE(s.value, 7);
    EXPECT_EQ(s.riskLevel, "High");
}

TEST(NEWSCalculatorTest, LowMediumRisk)
{
    Parameters p = {30, 96, false, 36.5, 120, 70, 'A'};
    Score s = NEWSCalculator::calculate(p);
    EXPECT_EQ(s.value, 3);
    EXPECT_EQ(s.riskLevel, "Low-Medium");
}

TEST(NEWSCalculatorTest, RespRateScore)
{
    Parameters p = {16, 98, false, 36.5, 120, 70, 'A'};
    p.respRate = 30;
    Score s = NEWSCalculator::calculate(p);
    EXPECT_EQ(s.value, 3);
    EXPECT_EQ(s.riskLevel, "Low-Medium");
}

TEST(NEWSCalculatorTest, OxygenSatScore)
{
    Parameters p = {16, 98, false, 36.5, 120, 70, 'A'};
    p.oxygenSat = 90;
    Score s = NEWSCalculator::calculate(p);
    EXPECT_EQ(s.value, 3);
    EXPECT_EQ(s.riskLevel, "Low-Medium");
}

TEST(NEWSCalculatorTest, SupplementalOxygen)
{
    Parameters p = {16, 98, false, 36.5, 120, 70, 'A'};
    p.supplementalOxygen = true;
    Score s = NEWSCalculator::calculate(p);
    EXPECT_EQ(s.value, 2);
    EXPECT_EQ(s.riskLevel, "Low");
}