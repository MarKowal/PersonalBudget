#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Markup.h"
#include "User.h"


using namespace std;

class UsersFile : public XmlFile {
  //  CMarkup xml;


public:
    UsersFile (string NAME_OF_FILE = "users.xml") : XmlFile("users.xml") {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void changeLoggedUserPasswordInFile(string oldPassword, string newPassword);

};

#endif

