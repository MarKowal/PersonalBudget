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
    personalBudget.changeLoggedUserPassword();
    personalBudget.printAllUsers();


    return 0;
}
