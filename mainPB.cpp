#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;
    personalBudget.registrationOfUser();
    personalBudget.printAllUsers();
    personalBudget.registrationOfUser();
    personalBudget.printAllUsers();


    return 0;
}
