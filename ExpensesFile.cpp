#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(FinancialData expense) {

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    if (uploadFile!=true) {
        xml.AddElem("EXPENSES");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("idFinancialData", expense.getIdFinancialData());
    xml.AddElem("idUser", expense.getIdUser());
    xml.AddElem("date", expense.getDate());
    xml.AddElem("description", expense.getDescription());
    xml.AddElem("amount", to_string(expense.getAmount()));
    xml.Save(getNAME_OF_FILE());
}

vector<FinancialData> ExpensesFile::loadExpensesFromFile(int idOfLoggedUser) {
    vector<FinancialData> expenses;
    FinancialData expense;

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    if (uploadFile == true) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("idFinancialData") ) {

            MCD_STR temporaryData1 = xml.GetData();
            expense.setIdFinancialData(atoi(MCD_2PCSZ(temporaryData1)));
            idOfLastExpense = atoi(MCD_2PCSZ(temporaryData1));

            xml.FindElem("idUser");
            MCD_STR temporaryData2 = xml.GetData();
            expense.setIdUser(atoi(MCD_2PCSZ(temporaryData2)));

            xml.FindElem("date");
            MCD_STR temporaryData3 = xml.GetData();
            expense.setDate(temporaryData3);

            xml.FindElem("description");
            MCD_STR temporaryData4 = xml.GetData();
            expense.setDescription(temporaryData4);

            xml.FindElem("amount");
            MCD_STR temporaryData5 = xml.GetData();
            expense.setAmount(stod(MCD_2PCSZ(temporaryData5)));

            if (idOfLoggedUser == expense.getIdUser()) {
                expenses.push_back(expense);
            }
        }
    }
    return expenses;
};

int ExpensesFile::getIdOfLastExpense() {
    return idOfLastExpense;
}

