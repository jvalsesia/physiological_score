#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

// Abstract base class for all UI indicators
class Observer
{
public:
    // virtual enables polymorphism, allowing derived classes to override base class methods
    // Marks the destructor (~) as virtual.
    // Ensures proper cleanup when deleting derived class objects via base class pointers.
    // Prevents memory leaks in inheritance hierarchies.

    virtual ~Observer()
    {
    }
    // We pass the relevant data needed for the dashboard and Led
    // forces derived classes (like Dashboard, Led) to implement update(...).
    // =0 has no implementation in the base class
    virtual void update(int bedNum, std::string name, std::string risk, std::string time) = 0;
};

#endif