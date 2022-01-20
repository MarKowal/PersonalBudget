#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "FinancialData.h"
#include "SupportingMethods.h"


using namespace std;

class BalanceSheet {

    struct lessThanKey;

    void sortVector(vector<FinancialData> &someVector);

public:
    BalanceSheet() {};
    void showBalanceSheetForPresentMonth(vector<FinancialData> incomes, vector<FinancialData> expenses);
    void showBalanceSheetForPreviousMonth(vector<FinancialData> incomes, vector<FinancialData> expenses);
    void showBalanceSheetForChosenPeriod(vector<FinancialData> incomes, vector<FinancialData> expenses);
};

#endif

