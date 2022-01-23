#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "SupportingMethods.h"
#include "UsersFile.h"

using namespace std;

class UserManager {
    vector <User> users;
    int idOfLoggedUser;
    UsersFile usersFile;

    User setDataOfNewUser();
    int getIdOfNewUser();
    bool ifLoginIsAlreadyUsed(string login);

public:
    UserManager();
    void registrationOfUser();
    void printAllUsers();
    int logInUser();
    int getIdOfLoggedUser();
    int logOutUser();
    void changeLoggedUserPassword();
};

#endif

