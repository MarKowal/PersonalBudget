#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>

#include "FinancialData.h"


using namespace std;

class IncomeManager {
    vector<FinancialData> incomes;

public:
   IncomeManager(int idOfLoggedUser);
   void addIncome(int idOfLoggedUser);

};

#endif

