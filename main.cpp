#include "ICU.hpp"
#include "Dashboard.hpp"
#include "Led.hpp"
#include <iostream>

int main()
{
    ICU myICU;
    // Create UI elements
    Dashboard mainScreen;
    Led warningLight;

    // Attach them to the ICU (The ICU doesn't need to know what they are, just that they are Observers)
    myICU.addObserver(&mainScreen);
    myICU.addObserver(&warningLight);

    char cmd;
    while (true)
    {

        std::cout << "'n'-new: \n";       // Option for adding new scores
        std::cout << "'h'-history: \n";   // Option for viewing patient history
        std::cout << "'a'-all: \n";       // Option for viewing all patients
        std::cout << "'d'-discharge: \n"; // Option for discharging patients
        std::cout << "'x'-exit: \n";      // Option to exit the program
        std::cin >> cmd;
        if (cmd == 'x')
            break;
        switch (cmd)
        {
        case 'n':
            myICU.processNewScore();
            break;
        case 'h':
            myICU.printPatientHistory();
            break;
        case 'a':
            myICU.printAllPatients();
            break;
        case 'd':
            myICU.dischargePatient();
            break;
        }
    }
    return 0;
}