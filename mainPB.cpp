#include <iostream>

#include "PersonalBudget.h"
#include "IncomeManager.h"
#include "IncomesFile.h"
#include "UsersFile.h"
#include "ExpenseManager.h"
#include "ExpensesFile.h"
#include "Menu.h"

#include "SupportingMethods.h"

using namespace std;

int main() {
    PersonalBudget personalBudget;
    char choice;
    Menu menu;

    while(true) {
        if (personalBudget.ifUserIsNotLogged()) {
            choice = menu.chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.registrationOfUser();
                break;
            case '2':
                personalBudget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = menu.chooseOptionFromLoggedUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showBalanceSheetForPresentMonth();
                break;
            case '4':
                personalBudget.showBalanceSheetForPreviousMonth();
                break;
            case '5':
                personalBudget.showBalanceSheetForChosenPeriod();
                break;
            case '6':
                personalBudget.changeLoggedUserPassword();
                break;
            case '7':
                personalBudget.logOutUser();
                break;
            }
        }
    }

    return 0;
}
