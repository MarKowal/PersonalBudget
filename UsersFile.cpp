#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    bool uploadFile = xml.Load(getNAME_OF_FILE());
    if (uploadFile!=true) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("idUser", user.getIdUser());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password",user.getPassword());
    xml.Save(getNAME_OF_FILE());
    cout<<"//User saved in xml file."<<endl;

}

vector<User> UsersFile::loadUsersFromFile() {
    vector<User> users;
    User user;

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    if (uploadFile == true) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("idUser") ) {

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
            cout<<"//User loaded to vector from XML file"<<endl;
        }
    }
    return users;
}

void UsersFile::changeLoggedUserPasswordInFile(string oldPassword, string newPassword) {
    cout<<"//oldPassword on UsersFile = "<<oldPassword<<endl;
    cout<<"//newPassword on UsersFile = "<<newPassword<<endl;

    string tempPasswordInfo;

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("password") ) {

        MCD_STR temporaryData = xml.GetData();
        tempPasswordInfo = MCD_2PCSZ(temporaryData);
        if (tempPasswordInfo == oldPassword) {
            xml.SetData(newPassword);
        }
        xml.Save(getNAME_OF_FILE());
    }
}

