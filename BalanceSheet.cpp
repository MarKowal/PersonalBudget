#include "BalanceSheet.h"

struct BalanceSheet::lessThanKey {
    bool operator() ( FinancialData struct1,  FinancialData struct2) {
        return (struct1.getDateAsNumber() < struct2.getDateAsNumber());
    }
};

void BalanceSheet::sortVector(vector<FinancialData> &someVector) {
    sort(someVector.begin(), someVector.end(), lessThanKey());
}

void BalanceSheet::showBalanceSheetForPresentMonth(vector<FinancialData> incomes, vector<FinancialData> expenses) {
    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    double difference = 0;

    int presentDayOfMonth = SupportingMethods::getPresentDayOfMonth();
    int presentDate = SupportingMethods::changeDateIntoNumber(SupportingMethods::getPresentDate());

    cout.setf(ios::fixed);
    cout.precision(2);
    sortVector(incomes);
    for (int i=0; i<incomes.size(); i++) {
        if(incomes[i].getDateAsNumber() >= (presentDate-presentDayOfMonth+1) && incomes[i].getDateAsNumber() <= presentDate) {
            cout<<"income IdFinancialData =   "<<incomes[i].getIdFinancialData()<<endl;
            cout<<"income IdUser =            "<<incomes[i].getIdUser()<<endl;
            cout<<"income Date =              "<<incomes[i].getDate()<<endl;
            cout<<"income Description =       "<<incomes[i].getDescription()<<endl;
            cout<<"income Amount =            "<<incomes[i].getAmount()<<endl;
            cout<<"income DateAsNumber =      "<<incomes[i].getDateAsNumber()<<endl;
            cout<<"---"<<endl;
            sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
        }
    }
    sortVector(expenses);
    for (int i=0; i<expenses.size(); i++) {
        if(expenses[i].getDateAsNumber() >= (presentDate-presentDayOfMonth+1) && expenses[i].getDateAsNumber() <= presentDate) {
            cout<<"expense IdFinancialData =     "<<expenses[i].getIdFinancialData()<<endl;
            cout<<"expense IdUser =              "<<expenses[i].getIdUser()<<endl;
            cout<<"expense Date =                "<<expenses[i].getDate()<<endl;
            cout<<"expense Description =         "<<expenses[i].getDescription()<<endl;
            cout<<"expense Amount =              "<<expenses[i].getAmount()<<endl;
            cout<<"expense DateAsNumber =        "<<expenses[i].getDateAsNumber()<<endl;
            cout<<"---"<<endl;
            sumOfExpenses = sumOfExpenses + expenses[i].getAmount();
        }
    }

    cout<<"sumOfIncomes = "<<sumOfIncomes<<endl;
    cout<<"sumOfExpenses = "<<sumOfExpenses<<endl;
    difference = sumOfIncomes - sumOfExpenses;
    cout<<"difference = "<<difference<<endl;
}

void BalanceSheet::showBalanceSheetForPreviousMonth(vector<FinancialData> incomes, vector<FinancialData> expenses) {
    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    double difference = 0;

    string previousMonth = SupportingMethods::getPreviousMonth();
    string previousYear = SupportingMethods::getPreviousYear(previousMonth);
    string daysInPreviousMonth = SupportingMethods::howManyDaysInMonth(previousMonth, previousYear);
    int previousMonthBegin = stoi(previousYear+previousMonth+"01");
    int previousMonthEnd = stoi(previousYear+previousMonth+daysInPreviousMonth);

    cout.setf(ios::fixed);
    cout.precision(2);
    sortVector(incomes);
    for (int i=0; i<incomes.size(); i++) {
        if(incomes[i].getDateAsNumber() >= previousMonthBegin && incomes[i].getDateAsNumber() <= previousMonthEnd) {
            cout<<"income IdFinancialData =   "<<incomes[i].getIdFinancialData()<<endl;
            cout<<"income IdUser =            "<<incomes[i].getIdUser()<<endl;
            cout<<"income Date =              "<<incomes[i].getDate()<<endl;
            cout<<"income Description =       "<<incomes[i].getDescription()<<endl;
            cout<<"income Amount =            "<<incomes[i].getAmount()<<endl;
            cout<<"income DateAsNumber =      "<<incomes[i].getDateAsNumber()<<endl;
            cout<<"---"<<endl;
            sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
        }
    }
    sortVector(expenses);
    for (int i=0; i<expenses.size(); i++) {
        if(expenses[i].getDateAsNumber() >= previousMonthBegin && expenses[i].getDateAsNumber() <= previousMonthEnd) {
            cout<<"expense IdFinancialData =     "<<expenses[i].getIdFinancialData()<<endl;
            cout<<"expense IdUser =              "<<expenses[i].getIdUser()<<endl;
            cout<<"expense Date =                "<<expenses[i].getDate()<<endl;
            cout<<"expense Description =         "<<expenses[i].getDescription()<<endl;
            cout<<"expense Amount =              "<<expenses[i].getAmount()<<endl;
            cout<<"expense DateAsNumber =        "<<expenses[i].getDateAsNumber()<<endl;
            cout<<"---"<<endl;
            sumOfExpenses = sumOfExpenses + expenses[i].getAmount();
        }
    }

    cout<<"sumOfIncomes = "<<sumOfIncomes<<endl;
    cout<<"sumOfExpenses = "<<sumOfExpenses<<endl;
    difference = sumOfIncomes - sumOfExpenses;
    cout<<"difference = "<<difference<<endl;
}

void BalanceSheet::showBalanceSheetForChosenPeriod(vector<FinancialData> incomes, vector<FinancialData> expenses) {
    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    double difference = 0;

    cout<<"Begin of period:"<<endl;
    string periodBegin = SupportingMethods::getDateFromUser();
    int termBegin = SupportingMethods::changeDateIntoNumber(periodBegin);
    cout<<"End of period:"<<endl;
    string periodEnd = SupportingMethods::getDateFromUser();
    int termEnd = SupportingMethods::changeDateIntoNumber(periodEnd);
    if (termBegin > termEnd) {
        cout<<"Wrong date End of period!"<<endl;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    sortVector(incomes);
    for (int i=0; i<incomes.size(); i++) {
        if(incomes[i].getDateAsNumber() >= termBegin && incomes[i].getDateAsNumber() <= termEnd) {
            cout<<"income IdFinancialData =   "<<incomes[i].getIdFinancialData()<<endl;
            cout<<"income IdUser =            "<<incomes[i].getIdUser()<<endl;
            cout<<"income Date =              "<<incomes[i].getDate()<<endl;
            cout<<"income Description =       "<<incomes[i].getDescription()<<endl;
            cout<<"income Amount =            "<<incomes[i].getAmount()<<endl;
            cout<<"income DateAsNumber =      "<<incomes[i].getDateAsNumber()<<endl;
            cout<<"---"<<endl;
            sumOfIncomes = sumOfIncomes + incomes[i].getAmount();
        }
    }

    sortVector(expenses);
    for (int i=0; i<expenses.size(); i++) {
        if(expenses[i].getDateAsNumber() >= termBegin && expenses[i].getDateAsNumber() <= termEnd) {
            cout<<"expense IdFinancialData =     "<<expenses[i].getIdFinancialData()<<endl;
            cout<<"expense IdUser =              "<<expenses[i].getIdUser()<<endl;
            cout<<"expense Date =                "<<expenses[i].getDate()<<endl;
            cout<<"expense Description =         "<<expenses[i].getDescription()<<endl;
            cout<<"expense Amount =              "<<expenses[i].getAmount()<<endl;
            cout<<"expense DateAsNumber =        "<<expenses[i].getDateAsNumber()<<endl;
            cout<<"---"<<endl;
            sumOfExpenses = sumOfExpenses + expenses[i].getAmount();
        }
    }

    cout<<"sumOfIncomes = "<<sumOfIncomes<<endl;
    cout<<"sumOfExpenses = "<<sumOfExpenses<<endl;
    difference = sumOfIncomes - sumOfExpenses;
    cout<<"difference = "<<difference<<endl;
}
