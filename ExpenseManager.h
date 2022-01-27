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
    void changeDateIntoNumber();
    bool checkIfFigureFrom0To9AsciiAndDot(string word);


public:
    ExpenseManager(int idOfLoggedUser);
    void addExpense(int idOfLoggedUser);
    void printAllExpenses();
    vector<FinancialData> getExpenses();
};

#endif

