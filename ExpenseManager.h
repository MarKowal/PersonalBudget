#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>

#include "FinancialData.h"
#include "SupportingMethods.h"
#include "ExpensesFile.h"

using namespace std;

class ExpenseManager {
    vector<FinancialData> expenses;
    ExpensesFile expensesFile;

    FinancialData setDataOfNewExpense(int idOfLoggedUser);
    int getIdOfNewExpense();
    string getNewDate();
    string getDateFromUser();
    bool checkYearFromUser(string timeInfo);
    bool checkMonthFromUser(string timeInfo);
    bool checkDayFromUser(string timeInfo, string month, string year);
    bool checkIfLeapYear(int year);


public:
   ExpenseManager(int idOfLoggedUser);
   void addExpense(int idOfLoggedUser);
   void printAllExpenses();

};

#endif

