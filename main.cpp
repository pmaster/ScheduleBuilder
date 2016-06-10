#include <iostream>
#include <fstream>
#include "MinClass.h"

using namespace std;

// make sure input file has a new line character (or several) at the end of the file

int main( )
{   ifstream in;
    ofstream out;
    in.open("testif.txt");
    out.open("outputFile.txt");

    MinClass CS8("CMPSC 8");
    in >> CS8;
    std::cout << CS8;

    MinClass CS56("CMPSC 56");
    in >> CS56;
    std::cout << CS56;

    MinClass CS130a("CMPSC 130a");
    in >> CS130a;
    std::cout << CS130a;

    /*vector<Event> sections1;
    sections1.push_back(Event(vecDays(R), 1600, 1650));
    sections1.push_back(Event(vecDays(R), 1700, 1750));
    sections1.push_back(Event(vecDays(R), 1800, 1850));
    vector<Lecture> lectures1;
    lectures1.push_back(Lecture(Event(vecDays(T, R), 1230, 1345), sections1));

    vector<Event> sections2;
    sections2.push_back(Event(vecDays(T), 900, 950));
    sections2.push_back(Event(vecDays(T), 1000, 1050));
    sections2.push_back(Event(vecDays(M, T, W, R, F), 1400, 1450));
    lectures1.push_back(Lecture(Event(vecDays(M, W), 1100, 1215), sections2));

    Event final1(1209, vecDays(W), 1200, 1500);
    MinClass cs56("CMPSC 56", lectures1);
    cs56.set_courseTitle("ADV APP PROGRAM");
    cs56.set_courseTitleFull("Advanced Applications Programming");
    //cs56.set_detailsFinal(final1);

    cout << cs56;

    out << cs56;*/
    in.close( );
    out.close( );

    return 0;
}
