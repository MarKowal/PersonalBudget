#include "IncomesFile.h"

void IncomesFile::addIncomeToIncomesFile(FinancialData income){

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    if (uploadFile!=true) {
            xml.AddElem("INCOMES");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("idFinancialData", income.getIdFinancialData());
    xml.AddElem("idUser", income.getIdUser());
    xml.AddElem("date", income.getDate());
    xml.AddElem("description", income.getDescription());
    xml.AddElem("amount", income.getAmount());
    xml.Save(getNAME_OF_FILE());
    cout<<"//Income saved in xml file."<<endl;
    //idOfLastIncome++;

}

int IncomesFile::getIdOfLastIncome() {   //czy ta metoda ma sens?
    return idOfLastIncome;
}

vector<FinancialData> IncomesFile::loadDataFromIncomesFile() {
    vector<FinancialData> incomes;
    FinancialData income;

    bool uploadFile = xml.Load(getNAME_OF_FILE());


};
