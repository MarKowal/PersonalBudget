#include "IncomeManager.h"

IncomeManager::IncomeManager(int idOfLoggedUser) {
    incomes = incomesFile.loadIncomeFromFile(idOfLoggedUser);
}

void IncomeManager::addIncome(int idOfLoggedUser) {
    FinancialData income = setDataOfNewIncome(idOfLoggedUser);
    incomes.push_back(income);
    cout<<"//from vector income.getAmount() = "<<income.getAmount()<<endl;
    cout << endl << "//Income saved in vector." << endl << endl;
    incomesFile.addIncomeToFile(income);
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

string IncomeManager::getNewDate() {
    string dateFromUser, year, month, day;
    char choice;
    string presentDate;

    cout<<"Today's income or other date? (T-today/O-other)";

    for (int attempt=0; attempt<3; attempt++) {
        cin>>choice;
        if (choice == 'T' || choice == 't') {
            presentDate = SupportingMethods::getPresentDateString();
            cout<<"Present date: "<<presentDate<<endl;;
            return presentDate;
        }
        if (choice == 'O' || choice == 'o') {
            dateFromUser = getDateFromUser();
            return dateFromUser;
        } else {
            cout<<"There is no such option."<<endl;
            cout<<"Try again. You have: "<<2-attempt<<" attempts left"<<endl;
        }
    }
    return "2000-01-01";
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

string IncomeManager::getDateFromUser() {
    string date, year, month, day, timeInfo;

    cout<<"Year of the income: ";
    cin>>timeInfo;
    if (checkYearFromUser(timeInfo) == true) {
        year = timeInfo;
        timeInfo = "";
    } else {
        return "error";
    }

    cout<<"Month of the income: ";
    cin>>timeInfo;
    if (checkMonthFromUser(timeInfo) == true) {
        month = timeInfo;
        timeInfo = "";
    } else {
        return "error";
    }
    if (month.length()<2) {
        month = "0" + month;
    }

    cout<<"Day of the income: ";
    cin>>timeInfo;
    if (checkDayFromUser(timeInfo, month, year) == true) {
        day = timeInfo;
        timeInfo = "";
    } else {
        return "error";
    }
    if (day.length()<2) {
        day = "0" + day;
    }

    date = year +"-"+ month +"-"+ day;
    cout<<"Your date: "<<date<<endl;
    return date;
}

bool IncomeManager::checkYearFromUser(string timeInfo) {
    if (stoi(timeInfo) >= 2000 && stoi(timeInfo) <= stoi(SupportingMethods::getPresentYear())) {
        return true;
    } else {
        cout<<"Wrong year. Should be from 2000 to "<<SupportingMethods::getPresentYear()<<"."<<endl;
        return false;
    }
}

bool IncomeManager::checkMonthFromUser(string timeInfo) {
    if (stoi(timeInfo) >= 1 && stoi(timeInfo) <= 12) {
        return true;
    } else {
        cout<<"Wrong month. Should be from 1 to 12."<<endl;
        return false;
    }
}

bool IncomeManager::checkDayFromUser(string timeInfo, string month, string year) {
    int daysInMonth = 0;
    switch(stoi(month)) {
    case 1:
        daysInMonth = 31;
        break;
    case 2:
        if (checkIfLeapYear(stoi(year)) == true) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
        break;
    case 3:
        daysInMonth = 31;
        break;
    case 4:
        daysInMonth = 30;
        break;
    case 5:
        daysInMonth = 31;
        break;
    case 6:
        daysInMonth = 30;
        break;
    case 7:
        daysInMonth = 31;
        break;
    case 8:
        daysInMonth = 31;
        break;
    case 9:
        daysInMonth = 30;
        break;
    case 10:
        daysInMonth = 31;
        break;
    case 11:
        daysInMonth = 30;
        break;
    case 12:
        daysInMonth = 31;
        break;
    default: {
        cout<<"Wrong month."<<endl;
    }
    }

    if (stoi(timeInfo) >= 1 && stoi(timeInfo) <= daysInMonth) {
        return true;
    } else {
        cout<<"Wrong day. Should be from 1 to "<<daysInMonth<<"."<<endl;
        return false;
    }
}

bool IncomeManager::checkIfLeapYear(int year) {
    if ((year%4 == 0)&&(year%100 != 0)) {
        return true;
    } else if (year%400 == 0) {
        return true;
    } else {
        return false;
    }
}
