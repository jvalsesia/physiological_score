#ifndef ICU_HPP
#define ICU_HPP

#include "Observer.hpp"
#include "Patient.hpp"
#include <map>

class ICU
{
private:
    Patient *beds[7];                  // Index 1-6
    std::vector<Observer *> observers; // List of UI elements
    void refreshUI();                  // Helper to update Dashboard/LED after a removal
public:
    ICU();
    ~ICU();
    void processNewScore();
    void printPatientHistory();
    void printAllPatients();
    void addObserver(Observer *obs) { observers.push_back(obs); }

    void notifyObservers(int bed, std::string name, std::string risk, std::string time)
    {
        for (auto obs : observers)
        {
            obs->update(bed, name, risk, time);
        }
    }

    void dischargePatient();
};

#endif