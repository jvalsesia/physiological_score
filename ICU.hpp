#ifndef ICU_HPP
#define ICU_HPP

#include "Patient.hpp"
#include <map>

class ICU
{
private:
    Patient *beds[7]; // Index 1-6
public:
    ICU();
    ~ICU();
    void processNewScore();
    void printPatientHistory();
    void printAllPatients();
};

#endif