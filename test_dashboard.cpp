#include <gtest/gtest.h>
#include "Dashboard.hpp"

TEST(DashboardTest, UpdateMethod)
{
    Dashboard d;
    // Test that update doesn't throw
    EXPECT_NO_THROW(d.update(1, "John Doe", "Medium", "2023-10-01 10:00"));
}

TEST(DashboardTest, UpdateDashboardInfo)
{
    Dashboard d;
    // Test that updateDashboardInfo doesn't throw
    EXPECT_NO_THROW(d.updateDashboardInfo(1, "John Doe", "Medium", "2023-10-01 10:00"));
}