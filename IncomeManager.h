#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>

#include "FinancialData.h"
#include "SupportingMethods.h"
#include "IncomesFile.h"


using namespace std;

class IncomeManager {
    vector<FinancialData> incomes;
    IncomesFile incomesFile;

    FinancialData setDataOfNewIncome(int idOfLoggedUser);
    int getIdOfNewIncome();
    string getNewDate();
    string getDateFromUser();
    bool checkYearFromUser(string timeInfo);
    bool checkMonthFromUser(string timeInfo);
    bool checkDayFromUser(string timeInfo, string month, string year);
    bool checkIfLeapYear(int year);

    void changeDateIntoNumber();


public:
    IncomeManager(int idOfLoggedUser);
    void addIncome(int idOfLoggedUser);
    void printAllIncomes();
    vector<FinancialData> getIncomes();
};

#endif

