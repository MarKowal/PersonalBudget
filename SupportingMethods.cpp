#include "SupportingMethods.h"

string SupportingMethods::uploadLine() {
    string input = "";
    cin.clear();
    cin.sync();
    getline(cin, input);
    return input;
}

string SupportingMethods::changeCommaToDot(string number) {
    for (int i=0; i<number.length(); i++) {
        if (number[i] == ',') {
            number[i] = '.';
        }
    }
    return number;
}

string SupportingMethods::getPresentDate() {
    time_t rawTime;
    tm timeInfo;
    int year, month, day;
    string date;

    time(&rawTime);
    timeInfo = *localtime(&rawTime);
    year = timeInfo.tm_year+1900;
    month = timeInfo.tm_mon+1;
    day = timeInfo.tm_mday;

    if (month <= 9 && day <= 9) {
        date = to_string(year) +"-0"+ to_string(month) +"-0"+ to_string(day); //to rozbic do osobnej funkcji?
    }
    if (month > 9 && day <= 9) {
        date = to_string(year) +"-"+ to_string(month) +"-0"+ to_string(day);
    }
    if (month <= 9 && day > 9) {
        date = to_string(year) +"-0"+ to_string(month) +"-"+ to_string(day);
    }
    if (month > 9 && day > 9) {
        date = to_string(year) +"-"+ to_string(month) +"-"+ to_string(day);
    }

    return date;
}

string SupportingMethods::getPresentYear() {
    time_t rawTime;
    tm timeInfo;
    int year;
    string yearStr;
    time(&rawTime);
    timeInfo = *localtime(&rawTime);
    year = timeInfo.tm_year+1900;
    yearStr = to_string(year);
    return yearStr;
}

int SupportingMethods::getPresentDayOfMonth() {
    time_t rawTime;
    tm timeInfo;
    int day;
    string yearStr;
    time(&rawTime);
    timeInfo = *localtime(&rawTime);
    day = timeInfo.tm_mday;
    return day;
}

int SupportingMethods::changeDateIntoNumber(string dateWithDashes) {
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
    return dateAsNumber;
}

int SupportingMethods::getPresentMonth() {
    time_t rawTime;
    tm timeInfo;
    int month;
    string yearStr;
    time(&rawTime);
    timeInfo = *localtime(&rawTime);
    month = timeInfo.tm_mon + 1;
    return month;
}

string SupportingMethods::getPreviousMonth() {
    time_t rawTime;
    tm timeInfo;
    int month;
    string yearStr;
    time(&rawTime);
    timeInfo = *localtime(&rawTime);
    month = timeInfo.tm_mon;
    if (month == 0) {
        return "12";
    }
    return to_string(month);
}

string SupportingMethods::getPreviousYear(string previousMonth) {
    int previousYear = 0;
    if (stoi(previousMonth) == 12) {
        previousYear = stoi(getPresentYear()) - 1;
    } else {
        previousYear = stoi(getPresentYear());
    }
    return to_string(previousYear);
}

bool SupportingMethods::checkIfLeapYear(int year) {
    if ((year%4 == 0)&&(year%100 != 0)) {
        return true;
    } else if (year%400 == 0) {
        return true;
    } else {
        return false;
    }
}

string SupportingMethods::howManyDaysInMonth(string month, string year) {
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
    return to_string(daysInMonth);
}
