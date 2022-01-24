#include "PersonalBudget.h"

void PersonalBudget::registrationOfUser() {
    userManager.registrationOfUser();
}

void PersonalBudget::printAllUsers() {
    userManager.printAllUsers();
}

void PersonalBudget::logInUser() {
    userManager.logInUser();
    if (userManager.getIdOfLoggedUser() != 0) {
        incomeManager = new IncomeManager(userManager.getIdOfLoggedUser());
        expenseManager = new ExpenseManager(userManager.getIdOfLoggedUser());
    }
}

void PersonalBudget::addIncome() {
    incomeManager -> addIncome(userManager.getIdOfLoggedUser());
}

void PersonalBudget::printAllIncomes() {
    incomeManager -> printAllIncomes();
}

void PersonalBudget::logOutUser() {
    userManager.logOutUser();
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
}

void PersonalBudget::changeLoggedUserPassword() {
    userManager.changeLoggedUserPassword();
}

void PersonalBudget::addExpense() {
    expenseManager -> addExpense(userManager.getIdOfLoggedUser());
}

void PersonalBudget::printAllExpenses() {
    expenseManager -> printAllExpenses();
}

void PersonalBudget::showBalanceSheetForPresentMonth() {
    balanceSheet.showBalanceSheetForPresentMonth(incomeManager->getIncomes(), expenseManager->getExpenses());
}

void PersonalBudget::showBalanceSheetForPreviousMonth() {
    balanceSheet.showBalanceSheetForPreviousMonth(incomeManager->getIncomes(), expenseManager->getExpenses());
}

void PersonalBudget::showBalanceSheetForChosenPeriod() {
    balanceSheet.showBalanceSheetForChosenPeriod(incomeManager->getIncomes(), expenseManager->getExpenses());
}

bool PersonalBudget::ifUserIsNotLogged() {
    if (userManager.getIdOfLoggedUser() == 0) return true;
    else return false;
}

