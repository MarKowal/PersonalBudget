#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "BalanceSheet.h"


using namespace std;

class PersonalBudget {
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    BalanceSheet balanceSheet;

public:
    PersonalBudget(){
        incomeManager = NULL;
        expenseManager = NULL;
    };
    ~PersonalBudget(){
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    };
    void registrationOfUser();
    void printAllUsers();
    void logInUser();
    void addIncome();
    void printAllIncomes();
    void logOutUser();
    void changeLoggedUserPassword();
    void addExpense();
    void printAllExpenses();
    void showBalanceSheetForPresentMonth();
    void showBalanceSheetForPreviousMonth();
    void showBalanceSheetForChosenPeriod();
    bool ifUserIsNotLogged();

};

#endif
