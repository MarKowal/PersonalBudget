#ifndef FINANCIALDATA_H
#define FINANCIALDATA_H

#include <iostream>
#include <iomanip>

using namespace std;

class FinancialData {
    int idFinancialData;
    int idUser;
    string date;
    string description;
    double amount;
    int dateAsNumber;

public:
   FinancialData(int idFinancialData = 0, int idUser = 0, string date = "",
                 string description = "", double amount = 0, int dateAsNumber = 0){
       this -> idFinancialData = idFinancialData;
       this -> idUser = idUser;
       this -> date = date;
       this -> description = description;
       this -> amount = amount;
       this -> dateAsNumber = dateAsNumber;
   };

    void setIdFinancialData(int newIdFinancialData);
    void setIdUser(int newIdUser);
    void setDate(string newDate);
    void setDescription(string newDescription);
    void setAmount(double newAmount);
    void setDateAsNumber(int newDateAsNumber);


    int getIdFinancialData();
    int getIdUser();
    string getDate();
    string getDescription();
    double getAmount();
    int getDateAsNumber();

};

#endif

