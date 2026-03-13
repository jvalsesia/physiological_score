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
        std::cout << "\n'n'-new 'h'-history 'a'-all 'x'-exit: ";
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
        }
    }
    return 0;
}