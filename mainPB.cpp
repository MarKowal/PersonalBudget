#include <iostream>

#include "PersonalBudget.h"
#include "IncomeManager.h"
#include "IncomesFile.h"
#include "UsersFile.h"



using namespace std;

int main()
{

    PersonalBudget personalBudget;

    //personalBudget.registrationOfUser();
    personalBudget.printAllUsers();
    personalBudget.logInUser();
    personalBudget.printAllIncomes();
    personalBudget.logOutUser();
    personalBudget.logInUser();
    personalBudget.printAllIncomes();


    return 0;
}
