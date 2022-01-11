#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(FinancialData income) {

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
    xml.AddElem("amount", to_string(income.getAmount()));
    xml.Save(getNAME_OF_FILE());
    cout<<"//Income saved in xml file."<<endl;
}

vector<FinancialData> IncomesFile::loadIncomesFromFile(int idOfLoggedUser) {
    vector<FinancialData> incomes;
    FinancialData income;

    bool uploadFile = xml.Load(getNAME_OF_FILE());
    if (uploadFile == true) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("idFinancialData") ) {

            MCD_STR temporaryData1 = xml.GetData();
            income.setIdFinancialData(atoi(MCD_2PCSZ(temporaryData1)));
            idOfLastIncome = atoi(MCD_2PCSZ(temporaryData1));

            xml.FindElem("idUser");
            MCD_STR temporaryData2 = xml.GetData();
            income.setIdUser(atoi(MCD_2PCSZ(temporaryData2)));

            xml.FindElem("date");
            MCD_STR temporaryData3 = xml.GetData();
            income.setDate(temporaryData3);

            xml.FindElem("description");
            MCD_STR temporaryData4 = xml.GetData();
            income.setDescription(temporaryData4);

            xml.FindElem("amount");
            MCD_STR temporaryData5 = xml.GetData();
            income.setAmount(stod(MCD_2PCSZ(temporaryData5)));

            if (idOfLoggedUser == income.getIdUser()) {
                incomes.push_back(income);
                cout<<"//income loaded to vector from XML file"<<endl;
            }
        }
    }
    return incomes;
};

int IncomesFile::getIdOfLastIncome() {
    return idOfLastIncome;
}
