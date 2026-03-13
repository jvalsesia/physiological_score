#ifndef DASHBOARD_HPP
#define DASHBOARD_HPP

#include "Observer.hpp"
#include <iostream>
#include <vector>

class Dashboard : public Observer
{
public:
    void update(int bedNum, std::string name, std::string risk, std::string time) override
    {
        updateDashboardInfo(bedNum, name, risk, time);
    }

    void updateDashboardInfo(int bedNum, std::string name, std::string risk, std::string time)
    {
        std::cout << "\n--- DASHBOARD UPDATE ---" << std::endl;
        std::cout << "Bed " << bedNum << " - " << name << " - Risk Level: "
                  << risk << " - " << time << std::endl;
        std::cout << "------------------------\n"
                  << std::endl;
    }
};

#endif