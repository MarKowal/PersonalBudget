#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Markup.h"
#include "FinancialData.h"


using namespace std;

class IncomesFile : public XmlFile {
    CMarkup xml; //a jakby to wrzucic do XmlFile i dziedziczyc?
    int idOfLastIncome;

public:
    IncomesFile(string NAME_OF_FILE = "incomes.xml", int idOfLastIncome = 0) : XmlFile("incomes.xml"){
        this -> idOfLastIncome = idOfLastIncome;
    }
    void addIncomeToFile(FinancialData income);
    int getIdOfLastIncome();
    vector<FinancialData> loadIncomesFromFile(int idOfLoggedUser);
};

#endif
