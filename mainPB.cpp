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

    IncomeManager income(14);
    income.printAllIncomes();


  /* FinancialData income = {2, 3, "1997-12-17", "salary", 3400};
    IncomesFile incomesFile;
    incomesFile.addIncomeToIncomesFile(income);
    income = {3, 4, "1998-05-03", "rent", 5100};
    incomesFile.addIncomeToIncomesFile(income);*/



    return 0;
}
