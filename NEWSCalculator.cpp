#include "NEWSCalculator.hpp"
#include <ctime>

Score NEWSCalculator::calculate(const Parameters &p)
{
    int total = 0;
    bool hasThreeInAny = false;

    // auto: compiler deduces the type (lambda object type is anonymous).

    // [&] : capture clause
    //  - captures local variables from surrounding scope by reference.
    //  - in this function, it allows checkScore to modify : total and hasThreeInAny

    auto checkScore = [&](int s)
    {
        total += s;
        if (s == 3)
            hasThreeInAny = true;
    };

    // So every time the code calls checkScore(3) or checkScore(2),
    // it updates running score and remembers if any score was 3.
    if (p.respRate <= 8 || p.respRate >= 25)
        checkScore(3);
    else if (p.respRate >= 21)
        checkScore(2);
    else if (p.respRate >= 9 && p.respRate <= 11)
        checkScore(1);

    if (p.oxygenSat <= 91)
        checkScore(3);
    else if (p.oxygenSat <= 93)
        checkScore(2);
    else if (p.oxygenSat <= 95)
        checkScore(1);

    if (p.supplementalOxygen)
        checkScore(2);

    if (p.temperature <= 35.0)
        checkScore(3);
    else if (p.temperature >= 39.1)
        checkScore(2);
    else if ((p.temperature >= 35.1 && p.temperature <= 36.0) || (p.temperature >= 38.1 && p.temperature <= 39.0))
        checkScore(1);

    if (p.systolicBP <= 90 || p.systolicBP >= 220)
        checkScore(3);
    else if (p.systolicBP <= 100)
        checkScore(2);
    else if (p.systolicBP <= 110)
        checkScore(1);

    if (p.heartRate <= 40 || p.heartRate >= 131)
        checkScore(3);
    else if (p.heartRate >= 111)
        checkScore(2);
    else if (p.heartRate <= 50 || (p.heartRate >= 91 && p.heartRate <= 110))
        checkScore(1);

    if (toupper(p.consciousness) != 'A')
        checkScore(3);

    std::string risk;
    if (total >= 7)
        risk = "High";
    else if (total >= 5)
        risk = "Medium";
    else if (hasThreeInAny)
        risk = "Low-Medium";
    else
        risk = "Low";

    return {total, risk, getCurrentTime()};
}

std::string NEWSCalculator::getCurrentTime()
{
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%d %b %Y %H:%M", localtime(&now));
    return std::string(buf);
}