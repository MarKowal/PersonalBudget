#include "ExpenseManager.h"

ExpenseManager::ExpenseManager(int idOfLoggedUser) {
    expenses = expensesFile.loadExpensesFromFile(idOfLoggedUser);
}

void ExpenseManager::addExpense(int idOfLoggedUser) {
    FinancialData expense = setDataOfNewExpense(idOfLoggedUser);
    expenses.push_back(expense);
    cout<<"//from vector expense.getAmount() = "<<expense.getAmount()<<endl;
    cout << endl << "//Expense saved in vector." << endl << endl;
    expensesFile.addExpenseToFile(expense);
    system("pause");
}

FinancialData ExpenseManager::setDataOfNewExpense(int idOfLoggedUser) {
    FinancialData expense;

    expense.setIdFinancialData(getIdOfNewExpense());
    expense.setIdUser(idOfLoggedUser);
    expense.setDate(getNewDate());
    cout<<"Type description of the expense: "<<endl;
    expense.setDescription(SupportingMethods::uploadLine());
    cout<<"Type amount of the expense: ";
    expense.setAmount(stod(SupportingMethods::changeCommaToDot(SupportingMethods::uploadLine())));

    return expense;
}

int ExpenseManager::getIdOfNewExpense() {
    if (expenses.empty() == true) {
        return expensesFile.getIdOfLastExpense()+1;
    } else {
        if(expensesFile.getIdOfLastExpense() > expenses.back().getIdFinancialData()) {
            return expensesFile.getIdOfLastExpense()+1;
        } else {
            return expenses.back().getIdFinancialData()+1;
        }
    }
};

string ExpenseManager::getNewDate() {
    string dateFromUser, year, month, day;
    char choice;
    string presentDate;

    cout<<"Today's expense or other date? (T-today/O-other)";

    for (int attempt=0; attempt<3; attempt++) {
        cin>>choice;
        if (choice == 'T' || choice == 't') {
            presentDate = SupportingMethods::getPresentDateString();
            cout<<"Present expense date: "<<presentDate<<endl;;
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

void ExpenseManager::printAllExpenses() {
    for (int i=0; i<expenses.size(); i++) {
        cout<<"expense IdFinancialData= "<<expenses[i].getIdFinancialData()<<endl;
        cout<<"expense IdUser= "<<expenses[i].getIdUser()<<endl;
        cout<<"expense Date= "<<expenses[i].getDate()<<endl;
        cout<<"expense Description= "<<expenses[i].getDescription()<<endl;
        cout<<"expense Amount= "<<expenses[i].getAmount()<<endl;
        cout<<"---"<<endl;
    }
}

string ExpenseManager::getDateFromUser() {
    string date, year, month, day, timeInfo;

    cout<<"Year of the expense: ";
    cin>>timeInfo;
    if (checkYearFromUser(timeInfo) == true) {
        year = timeInfo;
        timeInfo = "";
    } else {
        return "error";
    }

    cout<<"Month of the expense: ";
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

    cout<<"Day of the expense: ";
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
    cout<<"Your expense date: "<<date<<endl;
    return date;
}

bool ExpenseManager::checkYearFromUser(string timeInfo) {
    if (stoi(timeInfo) >= 2000 && stoi(timeInfo) <= stoi(SupportingMethods::getPresentYear())) {
        return true;
    } else {
        cout<<"Wrong year. Should be from 2000 to "<<SupportingMethods::getPresentYear()<<"."<<endl;
        return false;
    }
}

bool ExpenseManager::checkMonthFromUser(string timeInfo) {
    if (stoi(timeInfo) >= 1 && stoi(timeInfo) <= 12) {
        return true;
    } else {
        cout<<"Wrong month. Should be from 1 to 12."<<endl;
        return false;
    }
}

bool ExpenseManager::checkDayFromUser(string timeInfo, string month, string year) {
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

bool ExpenseManager::checkIfLeapYear(int year) {
    if ((year%4 == 0)&&(year%100 != 0)) {
        return true;
    } else if (year%400 == 0) {
        return true;
    } else {
        return false;
    }
}

