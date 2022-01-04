#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Markup.h"
#include "FinancialData.h"


using namespace std;

class IncomesFile : public XmlFile {
    CMarkup xml;
    int idOfLastIncome; //czy ta zmienna ma sens?


public:
    IncomesFile(string NAME_OF_FILE = "incomes.xml", int idOfLastIncome = 0) : XmlFile("incomes.xml"){
    this -> idOfLastIncome = idOfLastIncome;
    }
    void addIncomeToIncomesFile(FinancialData income);
    int getIdOfLastIncome(); //czy ta metoda ma sens?
    vector<FinancialData> loadDataFromIncomesFile();


};

#endif
