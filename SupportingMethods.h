#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class SupportingMethods {

    static bool checkYearFromUser(string timeInfo);
    static bool checkMonthFromUser(string timeInfo);
    static bool checkDayFromUser(string timeInfo, string month, string year);
    static bool checkIfFigureFrom0To9ASCII(string word);
    static bool testingDateFromUser(string year, string month, string day);
    static bool checkIfLeapYear(int year);

public:
    SupportingMethods(){};
    static string uploadLine();
    static string changeCommaToDot(string number);
    static char setSign();

    static string getPresentDate();
    static string getPresentYear();
    static int getPresentDayOfMonth();
    static int changeDateIntoNumber(string dateWithDashes);
    static int getPresentMonth();
    static string getPreviousMonth();
    static string getPreviousYear(string previousMonth);
    static string howManyDaysInMonth(string month, string year);
    static string getDateFromUser();
    static string getNewDate();
    static string conversionDoubleToString(double number);

};

#endif
