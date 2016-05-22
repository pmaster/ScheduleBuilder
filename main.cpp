#include <iostream>
#include "MinClass.h"

using namespace std;

std::vector<DayOfTheWeek> vecDays(DayOfTheWeek a = invalid, DayOfTheWeek b = invalid,
                                  DayOfTheWeek c = invalid, DayOfTheWeek d = invalid,
                                  DayOfTheWeek e = invalid, DayOfTheWeek f = invalid,
                                  DayOfTheWeek g = invalid) {
    vector<DayOfTheWeek> days;
    if (a != invalid) {
        days.push_back(a);
        if (b != invalid) {
            days.push_back(b);
            if (c != invalid) {
                days.push_back(c);
                if (d != invalid) {
                    days.push_back(d);
                    if (e != invalid) {
                        days.push_back(e);
                        if (f != invalid) {
                            days.push_back(f);
                            if (g != invalid)
                                days.push_back(g);}}}}}}
    return days;
}

int main()
{
    vector<MinClass::Event> sections1;
    sections1.push_back(MinClass::Event(vecDays(R), 1600, 1650));
    sections1.push_back(MinClass::Event(vecDays(R), 1700, 1750));
    sections1.push_back(MinClass::Event(vecDays(R), 1800, 1850));
    vector<MinClass::Lecture> lectures1;
    //lectures1.push_back(Event(std::vector<DayOfTheWeek>sections1

    MinClass::Event final1;
    MinClass cs56("CMPSC 56", lectures1);
    cs56.set_detailsFinal(final1);

    //cout << cs56.get_lectures( )

    return 0;
}
