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
    cout << endl << "//Expense saved in vector." << endl << endl;
    expensesFile.addExpenseToFile(expense);
    changeDateIntoNumber();
    system("pause");
}

FinancialData ExpenseManager::setDataOfNewExpense(int idOfLoggedUser) {
    FinancialData expense;

    expense.setIdFinancialData(getIdOfNewExpense());
    expense.setIdUser(idOfLoggedUser);
    expense.setDate(SupportingMethods::getNewDate());
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
