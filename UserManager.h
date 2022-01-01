#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "SupportingMethods.h"



using namespace std;

class UserManager {
    vector <User> users;
    int idOfLoggedUser;

    User setDataOfNewUser();
    int getIdOfNewUser();
    bool ifLoginIsAlreadyUsed(string login);


public:
    UserManager(){
        idOfLoggedUser = 0;
    };

    void registrationOfUser();
    void printAllUsers();
    int logInUser();
    int getIdOfLoggedUser();


};

#endif

