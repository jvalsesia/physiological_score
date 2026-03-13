#include "ICU.hpp"
#include <iostream>

int main()
{
    ICU myICU;
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