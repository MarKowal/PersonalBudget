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
    IncomeManager incomes(14);
    incomes.printAllIncomes();



    return 0;
}
