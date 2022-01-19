#include <iostream>

#include "PersonalBudget.h"
#include "IncomeManager.h"
#include "IncomesFile.h"
#include "UsersFile.h"
#include "ExpenseManager.h"
#include "ExpensesFile.h"

using namespace std;

int main()
{


    PersonalBudget personalBudget;

    personalBudget.printAllUsers();
    personalBudget.logInUser();
    personalBudget.showBalanceSheetForChosenPeriod();




   //IncomeManager incomes(14);
    //incomes.printAllIncomes();

    /*
    vector < FinancialData > vec;

    FinancialData income1 = {1, 1, "2022-01-12", "loan", 1345, 20220112};
    FinancialData income2 = {2, 2, "2021-12-05", "credit", 65, 20211205};
    FinancialData income3 = {3, 2, "2022-01-01", "big gift", 891, 20220101};
    FinancialData income4 = {4, 3, "2021-12-08", "small gift", 91, 20211208};
    FinancialData income5 = {5, 1, "2021-12-31", "medium gift", 57, 20211231};

    vec.push_back(income1);
    vec.push_back(income2);
    vec.push_back(income3);
    vec.push_back(income4);
    vec.push_back(income5);

    BalanceSheet balanceSheet;
   // balanceSheet.showBalanceSheetForPresentMonth(vec);
   // balanceSheet.showBalanceSheetForPreviousMonth(vec);
    balanceSheet.showBalanceSheetForChosenPeriod(vec);
    */

    return 0;
}
