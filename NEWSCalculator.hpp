#ifndef NEWSCALCULATOR_HPP
#define NEWSCALCULATOR_HPP

#include "Parameters.hpp"

class NEWSCalculator
{
public:
    static Score calculate(const Parameters &p);

private:
    static std::string getCurrentTime();
};

#endif