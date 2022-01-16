#include "FinancialData.h"

void FinancialData::setIdFinancialData(int newIdFinancialData) {
    if (newIdFinancialData > 0) {
        idFinancialData = newIdFinancialData;
    }
}

void FinancialData::setIdUser(int newIdUser) {
    if (newIdUser > 0) {
        idUser = newIdUser;
    }
}

void FinancialData::setDate(string newDate) {
    date = newDate;
}

void FinancialData::setDescription(string newDescription) {
    description = newDescription;
}

void FinancialData::setAmount(double newAmount) {
    if (newAmount > 0) {
        amount = newAmount;
    }
}

void FinancialData::setDateAsNumber(int newDateAsNumber) {
    if (newDateAsNumber >= 20000101) {
        dateAsNumber = newDateAsNumber;
    }
}



int FinancialData::getIdFinancialData() {
    return idFinancialData;
}

int FinancialData::getIdUser() {
    return idUser;
}

string FinancialData::getDate() {
    return date;
}
string FinancialData::getDescription() {
    return description;
}

double FinancialData::getAmount() {
    return amount;
}

int FinancialData::getDateAsNumber() {
    return dateAsNumber;
}

