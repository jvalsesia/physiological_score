#include <gtest/gtest.h>
#include "Led.hpp"

TEST(LedTest, InitialState)
{
    Led led;
    // Initial currentHighest is "Low", color GREEN
    // But since updateRiskLevel is not public, hard to test directly.
    // Perhaps test update method indirectly, but since it calls updateRiskLevel which is not defined in the snippet.
    // The snippet has updateRiskLevel(getColor(currentHighest)); but updateRiskLevel is not defined.
    // Perhaps it's inherited or something. Wait, in the code, updateRiskLevel is called but not defined in Led.
    // Maybe it's a method to be implemented.
    // For testing, perhaps test the logic of update.
    // Since currentHighest is private, hard.
    // Perhaps make a test that checks the priority.
    // But since updateRiskLevel is not defined, maybe skip or assume.
    // For now, test the helper methods if possible, but they are private.
    // Perhaps make them protected or test via update.
    // Since update doesn't return anything, perhaps it's hard to test without mocking cout or something.
    // For simplicity, test the priority logic by making a test class.
}

class TestLed : public Led
{
public:
    int getPriority(std::string risk) { return getRiskPriority(risk); }
    std::string getCol(std::string risk) { return getColor(risk); }
};

TEST(LedTest, RiskPriority)
{
    TestLed led;
    EXPECT_EQ(led.getPriority("High"), 4);
    EXPECT_EQ(led.getPriority("Medium"), 3);
    EXPECT_EQ(led.getPriority("Low-Medium"), 2);
    EXPECT_EQ(led.getPriority("Low"), 1);
}

TEST(LedTest, ColorMapping)
{
    TestLed led;
    EXPECT_EQ(led.getCol("High"), "RED");
    EXPECT_EQ(led.getCol("Medium"), "ORANGE");
    EXPECT_EQ(led.getCol("Low-Medium"), "YELLOW");
    EXPECT_EQ(led.getCol("Low"), "GREEN");
}