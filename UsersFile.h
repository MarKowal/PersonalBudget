#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Markup.h"
#include "User.h"


using namespace std;

class UsersFile : public XmlFile {
    CMarkup xml; //a jakby to wrzucic do XmlFile i dziedziczyc?


public:
    UsersFile (string NAME_OF_FILE = "users.xml") : XmlFile("users.xml") {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void changeLoggedUserPasswordInFile(string oldPassword, string newPassword);

};

#endif

