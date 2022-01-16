#include <iostream>

#include "PersonalBudget.h"
#include "IncomeManager.h"
#include "IncomesFile.h"
#include "UsersFile.h"
#include "ExpenseManager.h"
#include "ExpensesFile.h"

using namespace std;

int main()
{
   /*
    PersonalBudget personalBudget;

    personalBudget.printAllUsers();
    personalBudget.logInUser();
    personalBudget.addExpense();
    personalBudget.addExpense();
    personalBudget.printAllExpenses();
    */

   // IncomeManager incomes(14);
   // incomes.printAllIncomes();

   vector < FinancialData > vec;

    FinancialData income1 = {11, 15, "2021-01-02", "loan", 1345, 2};
    FinancialData income2 = {24, 9, "2021-03-05", "credit", 65, 3};
    FinancialData income3 = {3, 4, "2021-09-07", "gift", 991, 1};

    vec.push_back(income1);
    vec.push_back(income2);
    vec.push_back(income3);


    BalanceSheet balanceSheet;
    balanceSheet.sortAllIncomes(vec);


    return 0;
}
