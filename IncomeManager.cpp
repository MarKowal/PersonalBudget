#include "IncomeManager.h"

IncomeManager::IncomeManager(int idOfLoggedUser) {
    incomes = incomesFile.loadIncomesFromFile(idOfLoggedUser);
    if (!incomes.empty()) {
            changeDateIntoNumber();
    }
}

void IncomeManager::addIncome(int idOfLoggedUser) {
    FinancialData income = setDataOfNewIncome(idOfLoggedUser);
    incomes.push_back(income);
    cout<<"//from vector income.getAmount() = "<<income.getAmount()<<endl;
    cout << endl << "//Income saved in vector." << endl << endl;
    incomesFile.addIncomeToFile(income);
    changeDateIntoNumber();
    system("pause");
}

FinancialData IncomeManager::setDataOfNewIncome(int idOfLoggedUser) {
    FinancialData income;

    income.setIdFinancialData(getIdOfNewIncome());
    income.setIdUser(idOfLoggedUser);
    income.setDate(SupportingMethods::getNewDate());
    cout<<"Type description of the income: "<<endl;
    income.setDescription(SupportingMethods::uploadLine());
    cout<<"Type amount of the income: ";
    income.setAmount(stod(SupportingMethods::changeCommaToDot(SupportingMethods::uploadLine())));

    return income;
}

int IncomeManager::getIdOfNewIncome() {
    if (incomes.empty() == true) {
        return incomesFile.getIdOfLastIncome()+1;
    } else {
        if(incomesFile.getIdOfLastIncome() > incomes.back().getIdFinancialData()) {
            return incomesFile.getIdOfLastIncome()+1;
        } else {
            return incomes.back().getIdFinancialData()+1;
        }
    }
};

void IncomeManager::printAllIncomes() {
    for (int i=0; i<incomes.size(); i++) {
        cout<<"income IdFinancialData = "<<incomes[i].getIdFinancialData()<<endl;
        cout<<"income IdUser = "<<incomes[i].getIdUser()<<endl;
        cout<<"income Date = "<<incomes[i].getDate()<<endl;
        cout<<"income Description = "<<incomes[i].getDescription()<<endl;
        cout<<"income Amount = "<<incomes[i].getAmount()<<endl;
        cout<<"income DateAsNumber = "<<incomes[i].getDateAsNumber()<<endl;
        cout<<"---"<<endl;
    }
}

void IncomeManager::changeDateIntoNumber() {
    for (int i=0; i<incomes.size(); i++) {
        string dateWithDashes = incomes[i].getDate();
        string dateWithoutDashes = "";
        int dateAsNumber = NULL;

        for (int i=0; i<dateWithDashes.length(); i++) {
            if (dateWithDashes[i] == '-') {
                continue;
            } else {
                dateWithoutDashes = dateWithoutDashes + dateWithDashes[i];
            }
        }
        dateAsNumber = stoi(dateWithoutDashes);
        incomes[i].setDateAsNumber(dateAsNumber);
    }
}

vector<FinancialData> IncomeManager::getIncomes() {
    return incomes;
}


