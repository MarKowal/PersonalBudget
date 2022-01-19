#include "BalanceSheet.h"

struct BalanceSheet::lessThanKey {
    bool operator() ( FinancialData struct1,  FinancialData struct2) {
        return (struct1.getDateAsNumber() < struct2.getDateAsNumber());
    }
};

void BalanceSheet::sortVector(vector<FinancialData> &someVector) {
    sort(someVector.begin(), someVector.end(), lessThanKey());
}

void BalanceSheet::showBalanceSheetForPresentMonth(vector<FinancialData> incomes) {
    sortVector(incomes);
    double sumOfIncomes = 0;  //ZMIENIC TYP ZEBY POKAZYWAL UJEMNE
    int presentDayOfMonth = SupportingMethods::getPresentDayOfMonth();
    int presentDate = SupportingMethods::changeDateIntoNumber(SupportingMethods::getPresentDate());

        for (int i=0; i<incomes.size(); i++) {
            if(incomes[i].getDateAsNumber() >= (presentDate-presentDayOfMonth+1) && incomes[i].getDateAsNumber() <= presentDate) {
                cout<<"income IdFinancialData = "<<incomes[i].getIdFinancialData()<<endl;
                cout<<"income IdUser = "<<incomes[i].getIdUser()<<endl;
                cout<<"income Date = "<<incomes[i].getDate()<<endl;
                cout<<"income Description = "<<incomes[i].getDescription()<<endl;
                cout<<"income Amount = "<<incomes[i].getAmount()<<endl;
                cout<<"income DateAsNumber = "<<incomes[i].getDateAsNumber()<<endl;
                cout<<"---"<<endl;
                sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
            }
        }
        cout<<"sumOfIncomes = "<<sumOfIncomes<<endl;

        //DOROBIE dateAsNumber W WYDATKACH, WKLEJE TUTAJ I POOROWNAM Z DOCHODAMI
}

void BalanceSheet::showBalanceSheetForPreviousMonth(vector<FinancialData> incomes) {
    sortVector(incomes);
    double sumOfIncomes = 0;  //ZMIENIC TYP ZEBY POKAZYWAL UJEMNE

    string previousMonth = SupportingMethods::getPreviousMonth();
    cout<<"previousMonth = "<<previousMonth<<endl;
    string previousYear = SupportingMethods::getPreviousYear(previousMonth);
    cout<<"previousYear = "<<previousYear<<endl;
    string daysInPreviousMonth = SupportingMethods::howManyDaysInMonth(previousMonth, previousYear);
    cout<<"daysInPreviousMonth = "<<daysInPreviousMonth<<endl;

    int previousMonthBegin = stoi(previousYear+previousMonth+"01");
    int previousMonthEnd = stoi(previousYear+previousMonth+daysInPreviousMonth);
    cout<<"previousMonthBegin = "<<previousMonthBegin<<endl;
    cout<<"previousMonthEnd = "<<previousMonthEnd<<endl;

    for (int i=0; i<incomes.size(); i++) {
        if(incomes[i].getDateAsNumber() >= previousMonthBegin && incomes[i].getDateAsNumber() <= previousMonthEnd) {
            cout<<"income IdFinancialData = "<<incomes[i].getIdFinancialData()<<endl;
            cout<<"income IdUser = "<<incomes[i].getIdUser()<<endl;
            cout<<"income Date = "<<incomes[i].getDate()<<endl;
            cout<<"income Description = "<<incomes[i].getDescription()<<endl;
            cout<<"income Amount = "<<incomes[i].getAmount()<<endl;
            cout<<"income DateAsNumber = "<<incomes[i].getDateAsNumber()<<endl;
            cout<<"---"<<endl;
            sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
        }
    }
    cout<<"sumOfIncomes = "<<sumOfIncomes<<endl;
}

