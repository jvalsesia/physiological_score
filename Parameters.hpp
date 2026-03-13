#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <string>
#include <cctype>

struct Parameters
{
    int respRate;
    int oxygenSat;
    bool supplementalOxygen;
    double temperature;
    int systolicBP;
    int heartRate;
    char consciousness;

    bool isValid() const
    {
        if (respRate < 0 || respRate > 150)
            return false;
        if (oxygenSat < 50 || oxygenSat > 100)
            return false;
        if (temperature < 20 || temperature > 50)
            return false;
        if (systolicBP < 0 || systolicBP > 300)
            return false;
        if (heartRate < 15 || heartRate > 250)
            return false;
        std::string validC = "AVPU";
        if (validC.find(toupper(consciousness)) == std::string::npos)
            return false;
        return true;
    }
};

struct Score
{
    int value;
    std::string riskLevel;
    std::string timestamp;
};

#endif