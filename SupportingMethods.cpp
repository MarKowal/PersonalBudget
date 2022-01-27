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
        date = to_string(year) +"-0"+ to_string(month) +"-0"+ to_string(day);
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
    }
    return to_string(daysInMonth);
}

string SupportingMethods::getDateFromUser() {
    string date, year, month, day, timeInfo;

    while(true) {
        date = "";
        year = "";
        month = "";
        day = "";
        timeInfo = "";
        cout<<"Type the date"<<endl;
        cout<<"- from 2000-01-01 till end of this month"<<endl;
        cout<<"- format yyyy-mm-dd:"<<endl;
        timeInfo = uploadLine();
        if (timeInfo.length() == 10) {
            for(int i=0; i<timeInfo.length(); i++) {
                if (i <= 3) {
                    year = year + timeInfo[i];
                } else if (i >= 5 && i <= 6) {
                    month = month + timeInfo[i];
                } else if (i >= 8 && i <= 9) {
                    day = day + timeInfo[i];
                }
            }
            if (testingDateFromUserIfFigure(year, month, day) == true) {
                if (testingDateFromUserIfCorrectWithCalendar(year, month, day) == true) {
                    date = year +"-"+ month +"-"+ day;
                    break;
                    return date;
                }
            }
        }
        cout<<"Wrong date. Try again..."<<endl;
    }
}

bool SupportingMethods::testingDateFromUserIfFigure(string year, string month, string day) {
    bool testFigureYear, testFigureMonth, testFgiureDay;

    if (checkIfFigureFrom0To9ASCII(year) == true) {
        testFigureYear = true;
    } else testFigureYear = false;

    if (checkIfFigureFrom0To9ASCII(month) == true) {
        testFigureMonth = true;
    } else testFigureMonth = false;

    if (checkIfFigureFrom0To9ASCII(day) == true) {
        testFgiureDay = true;
    } else testFgiureDay = false;

    if (testFigureYear == true && testFigureMonth == true && testFgiureDay == true) {
        return true;
    } else return false;
}

bool SupportingMethods::testingDateFromUserIfCorrectWithCalendar(string year, string month, string day) {
    bool testCalendarYear, testCalendarMonth, testCalendarDay;

    if (checkYearFromUser(year) == true) {
        testCalendarYear = true;
    } else testCalendarYear = false;

    if (checkMonthFromUser(month, year) == true) {
        testCalendarMonth = true;
    } else testCalendarMonth = false;

    if (checkDayFromUser(day, month, year) == true) {
        testCalendarDay = true;
    } else testCalendarDay = false;

    if (testCalendarYear == true && testCalendarMonth == true && testCalendarDay == true) {
        return true;
    } else return false;
}

bool SupportingMethods::checkYearFromUser(string year) {
    if (stoi(year) >= 2000 && stoi(year) <= stoi(getPresentYear())) {
        return true;
    } else return false;
}

bool SupportingMethods::checkMonthFromUser(string month, string year) {

    if (stoi(year) == stoi(getPresentYear())) {
        if (stoi(month) <= getPresentMonth()) {
            return true;
        } else return false;
    }
    if (stoi(month) >= 1 && stoi(month) <= 12) {
        return true;
    } else return false;
}

bool SupportingMethods::checkDayFromUser(string day, string month, string year) {
    if (stoi(day) >= 1 && stoi(day) <= stoi(howManyDaysInMonth(month, year))) {
        return true;
    } else return false;
}

string SupportingMethods::getNewDate() {
    string dateFromUser, year, month, day;
    char choice;
    string presentDate;

    while(true) {
        cout<<"Today's income or other date? (T-today/O-other)";
        cin>>choice;
        if (choice == 'T' || choice == 't') {
            presentDate = getPresentDate();
            cout<<"Present date: "<<presentDate<<endl;
            return presentDate;
        }
        if (choice == 'O' || choice == 'o') {
            dateFromUser = getDateFromUser();
            return dateFromUser;
        } else {
            cout<<"There is no such option. Try again..."<<endl<<endl;
        }
    }
}

char SupportingMethods::setSign() {
    string input = "";
    char sign  = {0};

    while (true) {
        getline(cin, input);
        if (input.length() == 1) {
            sign = input[0];
            break;
        }
    }
    return sign;
}

bool SupportingMethods::checkIfFigureFrom0To9ASCII(string word) {
    bool testFigure;
    int ASCII = NULL;
    for (int i=0; i<word.length(); i++) {
        ASCII = (int)word[i];
        if (ASCII >= 48 && ASCII <= 57) {
            testFigure = true;
        } else {
            testFigure = false;
            break;
        }
    }
    return testFigure;
}

string SupportingMethods::conversionDoubleToString(double number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

