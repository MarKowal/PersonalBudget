#include "IncomeManager.h"

void IncomeManager::addIncome(int idOfLoggedUser) {
    FinancialData income = setDataOfNewIncome(idOfLoggedUser);
    incomes.push_back(income);
    cout << endl << "//Income saved in vector." << endl << endl;
    incomesFile.addIncomeToIncomesFile(income);
    system("pause");
}

FinancialData IncomeManager::setDataOfNewIncome(int idOfLoggedUser) {
    FinancialData income;

    income.setIdFinancialData(getIdOfNewIncome());
    income.setIdUser(idOfLoggedUser);
    income.setDate(getNewDate());
    cout<<"Type description of the income: "<<endl;
    income.setDescription(SupportingMethods::uploadLine());
    cout<<"Type amount of the income: ";
    int amount = 0; //trzeba zamienic na funkcje pobierajaca i zamieniajaca przecinek na kropke
    cin>>amount;
    income.setAmount(amount);

    return income;
}

int IncomeManager::getIdOfNewIncome() {
    if (incomes.empty() == true) {
        return 1;
    } else {
        return incomes.back().getIdFinancialData()+1;
    }
}

string IncomeManager::getNewDate() {
    string date, year, month, day;

    //najpierw zapytaj czy uzyc biezacej daty, potem wpisywanie wlasnej daty
    cout<<"Type year of the income: ";
    cin>>year;
    cout<<"Type month of the income: ";
    cin>>month;
    cout<<"Type day of the income: ";
    cin>>day;
    //ogarnac kwestie zera przed pojedyncza cyfra
    date = year +"-"+ month +"-"+ day;
    return date;
}

void IncomeManager::printAllIncomes() {
    for (int i=0; i<incomes.size(); i++) {
        cout<<"IdFinancialData= "<<incomes[i].getIdFinancialData()<<endl;
        cout<<"IdUser= "<<incomes[i].getIdUser()<<endl;
        cout<<"Date= "<<incomes[i].getDate()<<endl;
        cout<<"Description= "<<incomes[i].getDescription()<<endl;
        cout<<"Amount= "<<incomes[i].getAmount()<<endl;
        cout<<"---"<<endl;
    }
}
