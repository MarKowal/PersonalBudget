#ifndef FINANCIALDATA_H
#define FINANCIALDATA_H

#include <iostream>

using namespace std;

class FinancialData {
    int idFinancialData;
    int idUser;
    string date;
    string description;
    int amount;

public:
   FinancialData(int idFinancialData = 0, int idUser = 0, string date = "",
                 string description = "", int amount = 0){
       this -> idFinancialData = idFinancialData;
       this -> idUser = idUser;
       this -> date = date;
       this -> description = description;
       this -> amount = amount;
   };

    void setIdFinancialData(int newIdFinancialData);
    void setIdUser(int newIdUser);
    void setDate(string newDate);
    void setDescription(string newDescription);
    void setAmount(int newAmount);

    int getIdFinancialData();
    int getIdUser();
    string getDate();
    string getDescription();
    int getAmount();
};

#endif

