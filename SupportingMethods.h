#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <ctime>

using namespace std;

class SupportingMethods {

    static bool checkYearFromUser(string timeInfo);
    static bool checkMonthFromUser(string timeInfo);
    static bool checkDayFromUser(string timeInfo, string month, string year);

public:
    SupportingMethods(){};
    static string uploadLine();
    static string changeCommaToDot(string number);
    static char setSign();

    //metody odnoszace sie do czasu, moze do osobnej klasy TimeMethods?
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

    //ZROBIC JAKAS METODE ZAMIAST ERROR W BLEDNEJ DACIE
    //KTORA BEDZIE ZMUSZALA DO POPRAWNEJ DATY

};

#endif
