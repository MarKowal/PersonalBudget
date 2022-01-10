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

            MCD_STR stringData1 = xml.GetData();
            user.setIdUser(atoi(MCD_2PCSZ(stringData1)));

            xml.FindElem("name");
            MCD_STR stringData2 = xml.GetData();
            user.setName(stringData2);

            xml.FindElem("surname");
            MCD_STR stringData3 = xml.GetData();
            user.setSurname(stringData3);

            xml.FindElem("login");
            MCD_STR stringData4 = xml.GetData();
            user.setLogin(stringData4);

            xml.FindElem("password");
            MCD_STR stringData5 = xml.GetData();
            user.setPassword(stringData5);

            users.push_back(user);
            cout<<"//User loaded to vector from XML file"<<endl;
        }
    }
    return users;
}


