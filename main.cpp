#include <iostream>
#include "MinClass.h"

using namespace std;

int main()
{
    vector<Event> sections1;
    sections1.push_back(Event(vecDays(R), 1600, 1650));
    sections1.push_back(Event(vecDays(R), 1700, 1750));
    sections1.push_back(Event(vecDays(R), 1800, 1850));
    vector<Lecture> lectures1;
    lectures1.push_back(Lecture(Event(vecDays(T, R), 1230, 1345), sections1));

    vector<Event> sections2;
    sections2.push_back(Event(vecDays(T), 900, 950));
    sections2.push_back(Event(vecDays(T), 1000, 1050));
    sections2.push_back(Event(vecDays(F), 1400, 1450));
    lectures1.push_back(Lecture(Event(vecDays(M, W), 1100, 1215), sections2));

    Event final1(1209, vecDays(W), 1200, 1500);
    MinClass cs56("CMPSC 56", lectures1);
    cs56.set_courseTitle("ADV APP PROGRAM");
    cs56.set_courseTitleFull("Advanced Applications Programming");
    //cs56.set_detailsFinal(final1);

    cout << cs56;

    return 0;
}
