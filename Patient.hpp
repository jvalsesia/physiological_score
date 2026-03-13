#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <vector>
#include <string>
#include "Parameters.hpp"

class Patient
{
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::vector<Score> history;

public:
    Patient(int id, std::string fn, std::string ln) : id(id), firstName(fn), lastName(ln) {}
    void addScore(Score s) { history.push_back(s); }
    int getId() const { return id; }
    std::string getFullName() const { return firstName + " " + lastName; }
    const std::vector<Score> &getHistory() const { return history; }
};
#endif