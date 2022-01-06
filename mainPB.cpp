#include <iostream>

#include "PersonalBudget.h"
#include "IncomeManager.h"
#include "IncomesFile.h"


using namespace std;

int main()
{
   /* PersonalBudget personalBudget;

    personalBudget.registrationOfUser();
    personalBudget.printAllUsers();
    personalBudget.logInUser();
    personalBudget.addIncome();
    personalBudget.addIncome();
    personalBudget.printAllIncomes();*/

  IncomeManager income(78);
    income.printAllIncomes();


/*
    FinancialData income = {2, 9, "1997-12-17", "salary", 1980.67};
    IncomesFile incomesFile;
    incomesFile.addIncomeToIncomesFile(income);
    */




    return 0;
}
