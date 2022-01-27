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
    incomesFile.addIncomeToFile(income);
    changeDateIntoNumber();
    system("pause");
}

FinancialData IncomeManager::setDataOfNewIncome(int idOfLoggedUser) {
    FinancialData income;
    string amount;

    income.setIdFinancialData(getIdOfNewIncome());
    income.setIdUser(idOfLoggedUser);
    income.setDate(SupportingMethods::getNewDate());
    cout<<"Type description of the income: "<<endl;
    income.setDescription(SupportingMethods::uploadLine());

    while(true) {
        cout<<"Type amount of the income: ";
        amount = SupportingMethods::changeCommaToDot(SupportingMethods::uploadLine());
        if (checkIfFigureFrom0To9AsciiAndDot(amount) == true) {
            income.setAmount(stod(amount));
            break;
        }
    } return income;
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
    cout.setf(ios::fixed);
    cout.precision(2);
    for (int i=0; i<incomes.size(); i++) {
        cout<<"income IdFinancialData =     "<<incomes[i].getIdFinancialData()<<endl;
        cout<<"income IdUser =              "<<incomes[i].getIdUser()<<endl;
        cout<<"income Date =                "<<incomes[i].getDate()<<endl;
        cout<<"income Description =         "<<incomes[i].getDescription()<<endl;
        cout<<"income Amount =              "<<incomes[i].getAmount()<<endl;
        cout<<"income DateAsNumber =        "<<incomes[i].getDateAsNumber()<<endl;
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

bool IncomeManager::checkIfFigureFrom0To9AsciiAndDot(string word) {
    bool testFigure;
    int ASCII = NULL;
    for (int i=0; i<word.length(); i++) {
        ASCII = (int)word[i];
        if (ASCII >= 48 && ASCII <= 57 || ASCII == 46 || ASCII == 44) {
            testFigure = true;
        } else {
            testFigure = false;
            break;
        }
    }
    return testFigure;
}
