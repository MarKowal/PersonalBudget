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
}

int IncomesFile::getIdOfLastIncome() {
    return idOfLastIncome;
}

vector<FinancialData> IncomesFile::loadDataFromIncomesFile(int idOfLoggedUser) {
    vector<FinancialData> incomes;
    FinancialData income;

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("idFinancialData") ) {

        MCD_STR stringData1 = xml.GetData();
        income.setIdFinancialData(atoi(MCD_2PCSZ(stringData1)));
        idOfLastIncome = atoi(MCD_2PCSZ(stringData1));

        xml.FindElem("idUser");
        MCD_STR stringData2 = xml.GetData();
        income.setIdUser(atoi(MCD_2PCSZ(stringData2)));

        xml.FindElem("date");
        MCD_STR stringData3 = xml.GetData();
        income.setDate(stringData3);

        xml.FindElem("description");
        MCD_STR stringData4 = xml.GetData();
        income.setDescription(stringData4);

        xml.FindElem("amount");
        MCD_STR stringData5 = xml.GetData();
        income.setAmount(atoi(MCD_2PCSZ(stringData5)));

        if (idOfLoggedUser == income.getIdUser()) {
            incomes.push_back(income);
            cout<<"//income loaded to vector from XML file"<<endl;
        }
    }
    return incomes;
};
