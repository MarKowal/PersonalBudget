#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <iostream>
#include <vector>
#include <algorithm>


#include "FinancialData.h"
#include "IncomeManager.h"


using namespace std;

class BalanceSheet {

    struct lessThanKey;  //struktura daje return - dziala jak klasa z funkcja?

public:
    BalanceSheet() {};
    void sortAllIncomes(vector<FinancialData> incomes);

};

#endif

