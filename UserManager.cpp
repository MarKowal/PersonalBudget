#include "UserManager.h"


UserManager::UserManager(){
        idOfLoggedUser = 0;
        users = usersFile.loadUsersFromFile();
    };

void UserManager::registrationOfUser() {
    User user = setDataOfNewUser();
    users.push_back(user);

    usersFile.addUserToFile(user);
    cout << endl << "New account is set correctly." << endl << endl;
    system("pause");
};

User UserManager::setDataOfNewUser() {
    User user;
    user.setIdUser(getIdOfNewUser());

    cout<<"Type your name: ";
    user.setName(SupportingMethods::uploadLine());

    cout<<"Type your surname: ";
    user.setSurname(SupportingMethods::uploadLine());

    do {
        cout<<"Type your login: ";
        user.setLogin(SupportingMethods::uploadLine());
    } while (ifLoginIsAlreadyUsed(user.getLogin()) == true);

    cout<<"Type your password: ";
    user.setPassword(SupportingMethods::uploadLine());

    return user;
};

int UserManager::getIdOfNewUser() {
    if (users.empty() == true) {
        return 1;
    } else {
        return users.back().getIdUser()+1;
    }
};

bool UserManager::ifLoginIsAlreadyUsed(string login) {
    for (int i=0; i<users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "This login is reserved by other user." << endl;
            return true;
        }
    }
    return false;
};

void UserManager::printAllUsers() {
    for (int i=0; i<users.size(); i++) {
        cout<<users[i].getIdUser()<<endl;
        cout<<users[i].getName()<<endl;
        cout<<users[i].getSurname()<<endl;
        cout<<users[i].getLogin()<<endl;
        cout<<users[i].getPassword()<<endl;
    }
}

int UserManager::logInUser() {
    User user;
    string login = "";
    string password = "";

    cout<<"Type your login: ";
    login = SupportingMethods::uploadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Type your password. Attempts left " << numberOfAttempts << ": ";
                password = SupportingMethods::uploadLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "You have sign in to the program." << endl << endl;
                    idOfLoggedUser = itr -> getIdUser();
                    system("pause");
                    return idOfLoggedUser;
                }
            }
            cout <<"Access password typed 3 times wrong."<<endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout <<"There is no user with such login. Access denied."<< endl << endl;
    system("pause");
    return 0;
}

int UserManager::getIdOfLoggedUser() {
    return idOfLoggedUser;
}

