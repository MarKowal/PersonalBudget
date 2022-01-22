#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "SupportingMethods.h"


using namespace std;

class Menu {

public:
    Menu (){};
    char chooseOptionFromMainMenu();
    char chooseOptionFromLoggedUserMenu();
};

#endif
