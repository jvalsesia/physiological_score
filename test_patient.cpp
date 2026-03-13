#include <gtest/gtest.h>
#include "Patient.hpp"

TEST(PatientTest, ConstructorAndGetters)
{
    Patient p(123, "John", "Doe");
    EXPECT_EQ(p.getId(), 123);
    EXPECT_EQ(p.getFullName(), "John Doe");
}

TEST(PatientTest, AddScore)
{
    Patient p(123, "John", "Doe");
    Score s = {5, "Medium", "2023-10-01 10:00"};
    p.addScore(s);
    const auto &history = p.getHistory();
    EXPECT_EQ(history.size(), 1);
    EXPECT_EQ(history[0].value, 5);
    EXPECT_EQ(history[0].riskLevel, "Medium");
}

TEST(PatientTest, MultipleScores)
{
    Patient p(123, "John", "Doe");
    Score s1 = {3, "Low", "2023-10-01 10:00"};
    Score s2 = {7, "High", "2023-10-01 11:00"};
    p.addScore(s1);
    p.addScore(s2);
    const auto &history = p.getHistory();
    EXPECT_EQ(history.size(), 2);
    EXPECT_EQ(history[1].value, 7);
}