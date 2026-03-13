#ifndef LED_HPP
#define LED_HPP

#include "Observer.hpp"
#include <iostream>
#include <map>
#include <string>

class Led : public Observer
{
private:
    std::string highestRisk = "Low";

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
        // Logic to always show the highest risk among all patients
        if (getRiskPriority(risk) >= getRiskPriority(highestRisk))
        {
            highestRisk = risk;
            updateRiskLevel(getColor(highestRisk));
        }
    }

    void updateRiskLevel(std::string color)
    {
        std::cout << "[ Led INDICATOR: " << color << " ]" << std::endl;
    }
};

#endif