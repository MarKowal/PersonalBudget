#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <ctime>

using namespace std;

class SupportingMethods {

public:
    SupportingMethods(){};
    static string uploadLine();
    static string changeCommaToDot(string number);

    static string getPresentDate();
    static string getPresentYear();
    static int getPresentDayOfMonth();
    static int changeDateIntoNumber(string dateWithDashes);
    static int getPresentMonth();
    static string getPreviousMonth();
    static string getPreviousYear(string previousMonth);
    static bool checkIfLeapYear(int year);
    static string howManyDaysInMonth(string month, string year);


};

#endif
