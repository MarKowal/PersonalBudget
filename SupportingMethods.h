#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class SupportingMethods {

    static bool checkYearFromUser(string year);
    static bool checkMonthFromUser(string month, string year);
    static bool checkDayFromUser(string day, string month, string year);
    static bool testingDateFromUserIfFigure(string year, string month, string day);
    static bool checkIfLeapYear(int year);
    static bool testingDateFromUserIfCorrectWithCalendar(string year, string month, string day);

public:
    SupportingMethods(){};
    static string uploadLine();
    static string changeCommaToDot(string number);
    static char setSign();
    static string conversionDoubleToString(double number);

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
    static bool checkIfFigureFrom0To9ASCII(string word);
};

#endif
