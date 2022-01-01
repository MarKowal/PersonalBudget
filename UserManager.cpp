#include "UserManager.h"

void UserManager::registrationOfUser() {
    User user = setDataOfNewUser();
    users.push_back(user);

    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "New account is set correctly." << endl << endl;
    system("pause");
};

User UserManager::setDataOfNewUser() {
    User user;
    user.setIdUser(getIdOfNewUser());

    cout<<"Type your name: ";
    user.setName(Supportingmethods::uploadLine());

    cout<<"Type your surname: ";
    user.setSurname(Supportingmethods::uploadLine());

    do {
        cout<<"Type your login: ";
        user.setLogin(Supportingmethods::uploadLine());
    } while (ifLoginIsAlreadyUsed(user.getLogin()) == true);

    cout<<"Type your password: ";
    user.setPassword(Supportingmethods::uploadLine());

    return user;
};

int UserManager::getIdOfNewUser() {
    if (users.empty() == true){
        return 1;
    }
    else {
        return users.back().getIdUser()+1;
    }
};

bool UserManager::ifLoginIsAlreadyUsed(string login) {
    for (int i=0; i<users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "This login is reserved by other user." << endl;
            return true;
        }
    } return false;
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


