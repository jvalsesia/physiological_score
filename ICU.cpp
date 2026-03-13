#include "ICU.hpp"
#include "NEWSCalculator.hpp"
#include <iostream>

ICU::ICU()
{
    for (int i = 0; i < 7; i++)
        beds[i] = nullptr;
}

ICU::~ICU()
{
    for (int i = 1; i <= 6; i++)
        delete beds[i];
}

void ICU::processNewScore()
{
    int bed;
    std::cout << "Enter bed number (1-6): ";
    std::cin >> bed;
    if (bed < 1 || bed > 6)
        return;

    if (!beds[bed])
    {
        int id;
        std::string fn, ln;
        std::cout << "Patient ID: ";
        std::cin >> id;
        std::cout << "First Name: ";
        std::cin >> fn;
        std::cout << "Last Name: ";
        std::cin >> ln;
        beds[bed] = new Patient(id, fn, ln);
    }

    Parameters p;
    std::cout << "Resp Rate: ";
    std::cin >> p.respRate;
    std::cout << "Oxygen Sat: ";
    std::cin >> p.oxygenSat;
    char s;
    std::cout << "Supp. Oxygen (y/n): ";
    std::cin >> s;
    p.supplementalOxygen = (s == 'y');
    std::cout << "Temp: ";
    std::cin >> p.temperature;
    std::cout << "Systolic BP: ";
    std::cin >> p.systolicBP;
    std::cout << "Heart Rate: ";
    std::cin >> p.heartRate;
    std::cout << "Consciousness (A/V/P/U): ";
    std::cin >> p.consciousness;

    if (p.isValid())
    {
        Score res = NEWSCalculator::calculate(p);
        beds[bed]->addScore(res);
        std::cout << "NEWS Score: " << res.value << ", Risk Level: " << res.riskLevel << "\n";
    }
    else
    {
        std::cout << "Invalid data. No NEWS score calculated.\n";
    }
}

void ICU::printPatientHistory()
{
    int id;
    std::cout << "Enter Patient ID: ";
    std::cin >> id;
    for (int i = 1; i <= 6; i++)
    {
        if (beds[i] && beds[i]->getId() == id)
        {
            std::cout << "Bed " << i << ": " << beds[i]->getId() << " - " << beds[i]->getFullName() << "\n";
            for (auto &s : beds[i]->getHistory())
                std::cout << s.timestamp << ", NEWS Score: " << s.value << ", Risk: " << s.riskLevel << "\n";
            return;
        }
    }
    std::cout << "No Patient with ID: " << id << "\n";
}

void ICU::printAllPatients()
{
    for (int i = 1; i <= 6; i++)
    {
        if (beds[i] && !beds[i]->getHistory().empty())
        {
            auto s = beds[i]->getHistory().back();
            std::cout << "Bed " << i << " - " << beds[i]->getId() << " - " << beds[i]->getFullName()
                      << " - Risk Level: " << s.riskLevel << " - " << s.timestamp << "\n";
        }
    }
}