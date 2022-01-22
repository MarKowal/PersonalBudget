#include "Menu.h"

char Menu::chooseOptionFromMainMenu() {
    char choice;
    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration of User" << endl;
    cout << "2. Log in User" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SupportingMethods::setSign();
    return choice;
}

char Menu::chooseOptionFromLoggedUserMenu() {
    char choice;
    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Balance sheet for present month" << endl;
    cout << "4. Balance sheet for previous month" << endl;
    cout << "5. Balance sheet for chosen period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change User password" << endl;
    cout << "7. Log out User" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SupportingMethods::setSign();
    return choice;
}

