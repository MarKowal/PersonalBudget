#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int idUser;
    string name, surname, login, password;

public:
    User(int idUser = 0, string name = "", string surname = "",
         string login = "", string password = "") {
        this -> idUser = idUser;
        this -> name = name;
        this -> surname = surname;
        this -> login = login;
        this -> password = password;
    }

    void setIdUser(int newIdUser);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getIdUser();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

};

#endif
