#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    bool uploadFile = xml.Load(getNAME_OF_FILE());
    if (uploadFile!=true) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("idUser", user.getIdUser());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password",user.getPassword());
    xml.Save(getNAME_OF_FILE());
}

vector<User> UsersFile::loadUsersFromFile() {
    vector<User> users;
    User user;

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    if (uploadFile == true) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User") ) {

            xml.IntoElem();

            xml.FindElem("idUser");
            MCD_STR temporaryData1 = xml.GetData();
            user.setIdUser(atoi(MCD_2PCSZ(temporaryData1)));

            xml.FindElem("name");
            MCD_STR temporaryData2 = xml.GetData();
            user.setName(temporaryData2);

            xml.FindElem("surname");
            MCD_STR temporaryData3 = xml.GetData();
            user.setSurname(temporaryData3);

            xml.FindElem("login");
            MCD_STR temporaryData4 = xml.GetData();
            user.setLogin(temporaryData4);

            xml.FindElem("password");
            MCD_STR temporaryData5 = xml.GetData();
            user.setPassword(temporaryData5);

            users.push_back(user);

            xml.OutOfElem();
        }
    }
    return users;
}

void UsersFile::changeLoggedUserPasswordInFile(string oldPassword, string newPassword) {
    string tempPasswordInfo;

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem("password");
        MCD_STR temporaryData = xml.GetData();
        tempPasswordInfo = MCD_2PCSZ(temporaryData);
        if (tempPasswordInfo == oldPassword) {
            xml.SetData(newPassword);
        }
        xml.OutOfElem();
        xml.Save(getNAME_OF_FILE());
    }
}

