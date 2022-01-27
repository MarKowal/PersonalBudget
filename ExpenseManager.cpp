#include "ExpenseManager.h"

ExpenseManager::ExpenseManager(int idOfLoggedUser) {
    expenses = expensesFile.loadExpensesFromFile(idOfLoggedUser);
    if (!expenses.empty()) {
        changeDateIntoNumber();
    }
}

void ExpenseManager::addExpense(int idOfLoggedUser) {
    FinancialData expense = setDataOfNewExpense(idOfLoggedUser);
    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);
    changeDateIntoNumber();
    system("pause");
}

FinancialData ExpenseManager::setDataOfNewExpense(int idOfLoggedUser) {
    FinancialData expense;
    string amount;

    expense.setIdFinancialData(getIdOfNewExpense());
    expense.setIdUser(idOfLoggedUser);
    expense.setDate(SupportingMethods::getNewDate());
    cout<<"Type description of the expense: "<<endl;
    expense.setDescription(SupportingMethods::uploadLine());

    while(true) {
        cout<<"Type amount of the income: ";
        amount = SupportingMethods::changeCommaToDot(SupportingMethods::uploadLine());
        if (checkIfFigureFrom0To9AsciiAndDot(amount) == true) {
            expense.setAmount(stod(amount));
            break;
        }
    } return expense;
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


void ExpenseManager::printAllExpenses() {
    cout.setf(ios::fixed);
    cout.precision(2);
    for (int i=0; i<expenses.size(); i++) {
        cout<<"expense IdFinancialData =     "<<expenses[i].getIdFinancialData()<<endl;
        cout<<"expense IdUser =              "<<expenses[i].getIdUser()<<endl;
        cout<<"expense Date =                "<<expenses[i].getDate()<<endl;
        cout<<"expense Description =         "<<expenses[i].getDescription()<<endl;
        cout<<"expense Amount =              "<<expenses[i].getAmount()<<endl;
        cout<<"expense DateAsNumber =        "<<expenses[i].getDateAsNumber()<<endl;
        cout<<"---"<<endl;
    }
}

void ExpenseManager::changeDateIntoNumber() {
    for (int i=0; i<expenses.size(); i++) {
        string dateWithDashes = expenses[i].getDate();
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
        expenses[i].setDateAsNumber(dateAsNumber);
    }
}

vector<FinancialData> ExpenseManager::getExpenses() {
    return expenses;
}

bool ExpenseManager::checkIfFigureFrom0To9AsciiAndDot(string word) {
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
