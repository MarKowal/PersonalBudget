#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Markup.h"
#include "FinancialData.h"


using namespace std;

class ExpensesFile : public XmlFile {
    CMarkup xml; //a jakby to wrzucic do XmlFile i dziedziczyc?
    int idOfLastExpense;

public:
    ExpensesFile(string NAME_OF_FILE = "expenses.xml", int idOfLastExpense = 0) : XmlFile("expenses.xml"){
        this -> idOfLastExpense = idOfLastExpense;
    }
    void addExpenseToFile(FinancialData expense);
    int getIdOfLastExpense();
    vector<FinancialData> loadExpensesFromFile(int idOfLoggedUser);
};

#endif
