#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <ctime>

using namespace std;

class SupportingMethods {

    static bool checkYearFromUser(string timeInfo);
    static bool checkMonthFromUser(string timeInfo);
    static bool checkDayFromUser(string timeInfo, string month, string year);
    static bool checkIfFigureFrom0To9ASCII(string word);


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
    static bool checkIfLeapYear(int year); //to przeniesc do private
    static string howManyDaysInMonth(string month, string year);
    static string getDateFromUser();
    static string getNewDate();
};

#endif
