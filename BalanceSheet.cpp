#include "BalanceSheet.h"

struct BalanceSheet::lessThanKey {
    bool operator() ( FinancialData struct1,  FinancialData struct2) {
        return (struct1.getDateAsNumber() < struct2.getDateAsNumber());
    }
};

void BalanceSheet::sortAllIncomes(vector<FinancialData> incomes) {
    for (int i=0; i<incomes.size(); i++) {
        cout<<"income IdFinancialData = "<<incomes[i].getIdFinancialData()<<endl;
        cout<<"income IdUser = "<<incomes[i].getIdUser()<<endl;
        cout<<"income Date = "<<incomes[i].getDate()<<endl;
        cout<<"income Description = "<<incomes[i].getDescription()<<endl;
        cout<<"income Amount = "<<incomes[i].getAmount()<<endl;
        cout<<"income DateAsNumber = "<<incomes[i].getDateAsNumber()<<endl;
        cout<<"---"<<endl;
    }

    sort(incomes.begin(), incomes.end(), lessThanKey());

    cout<<endl<<"AFTER SORTING:"<<endl;
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

