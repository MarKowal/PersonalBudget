#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    personalBudget.registrationOfUser();
    personalBudget.printAllUsers();
    personalBudget.logInUser();


    return 0;
}
