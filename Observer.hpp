#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

// Abstract base class for all UI indicators
class Observer
{
public:
    virtual ~Observer() {}
    // We pass the relevant data needed for the dashboard and Led
    virtual void update(int bedNum, std::string name, std::string risk, std::string time) = 0;
};

#endif