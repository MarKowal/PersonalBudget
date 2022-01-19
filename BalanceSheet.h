#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "FinancialData.h"
#include "SupportingMethods.h"


using namespace std;

class BalanceSheet {

    struct lessThanKey;  //struktura daje return - dziala jak klasa z funkcja?

    void sortVector(vector<FinancialData> &someVector);

public:
    BalanceSheet() {};
    void showBalanceSheetForPresentMonth(vector<FinancialData> incomes);
    void showBalanceSheetForPreviousMonth(vector<FinancialData> incomes);
    void showBalanceSheetForChosenPeriod(vector<FinancialData> incomes);
};

#endif

