#include <iostream>

#include "PersonalBudget.h"
#include "IncomeManager.h"
#include "IncomesFile.h"


using namespace std;

int main()
{
    PersonalBudget personalBudget;

    personalBudget.registrationOfUser();
    personalBudget.printAllUsers();
    personalBudget.logInUser();
    personalBudget.addIncome();
    personalBudget.printAllIncomes();

    return 0;
}
