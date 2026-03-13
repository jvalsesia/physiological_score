#ifndef LED_HPP
#define LED_HPP

#include "Observer.hpp"
#include <iostream>
#include <map>
#include <string>

class Led : public Observer
{
private:
    std::string currentHighest = "Low";

    // Helper to determine risk priority for the Led
    int getRiskPriority(std::string risk)
    {
        if (risk == "High")
            return 4;
        if (risk == "Medium")
            return 3;
        if (risk == "Low-Medium")
            return 2;
        return 1;
    }

    std::string getColor(std::string risk)
    {
        if (risk == "High")
            return "RED";
        if (risk == "Medium")
            return "ORANGE";
        if (risk == "Low-Medium")
            return "YELLOW";
        return "GREEN";
    }

public:
    void update(int bedNum, std::string name, std::string risk, std::string time) override
    {
        // Simple logic: if this is a system reset (bed 0), force Low.
        // Otherwise, use the standard comparison logic.
        if (bedNum == 0)
            currentHighest = "Low";

        if (getRiskPriority(risk) >= getRiskPriority(currentHighest))
        {
            currentHighest = risk;
        }
        updateRiskLevel(getColor(currentHighest));
    }

    void updateRiskLevel(std::string color)
    {
        std::cout << "[ Led INDICATOR: " << color << " ]" << std::endl;
    }
};

#endif