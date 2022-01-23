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
        cout<<"Type the date in format yyyy-mm-dd: "<<endl;
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
            if (testingDateFromUser(year, month, day) == true) {
                date = year +"-"+ month +"-"+ day;
                break;
                return date;
            }
        }
        cout<<"Format must be yyyy-mm-dd. Try again..."<<endl;
    }


    /*
    II VERSION - CODE FOR TYPING ONE AFTER ANOTHER YEAR, MONTH AND DAY:
    while(true) {
        cout<<"Year:";
        cin>>timeInfo;
        if (checkIfFigureFrom0To9ASCII(timeInfo) == true) {
            if (checkYearFromUser(timeInfo) == true) {
                year = timeInfo;
                timeInfo = "";
                break;
            }
        }
        cout<<"Try again..."<<endl;
    }

    while(true) {
        cout<<"Month:";
        cin>>timeInfo;
        if (checkIfFigureFrom0To9ASCII(timeInfo) == true) {
            if (checkMonthFromUser(timeInfo) == true) {
                month = timeInfo;
                timeInfo = "";
                break;
            }
        }
        cout<<"Try again..."<<endl;
    }
    if (month.length()<2) {
        month = "0" + month;
    }

    while(true) {
        cout<<"Day:";
        cin>>timeInfo;
        if (checkIfFigureFrom0To9ASCII(timeInfo) == true) {
            if (checkDayFromUser(timeInfo, month, year) == true) {
                day = timeInfo;
                timeInfo = "";
                break;
            }
            cout<<"Try again..."<<endl;
        }
    }
    if (day.length()<2) {
        day = "0" + day;
    }

    date = year +"-"+ month +"-"+ day;
    cout<<"Your date: "<<date<<endl;
    return date;
    */
}

bool SupportingMethods::testingDateFromUser(string year, string month, string day) {
    bool testYear, testMonth, testDay;

    if (checkIfFigureFrom0To9ASCII(year) == true) {
        if (checkYearFromUser(year) == true) {
            testYear = true;
        } else {
            testYear = false;
            return false;
        }
    } else {
        testYear = false;
        return false;;
    }

    if (checkIfFigureFrom0To9ASCII(month) == true) {
        if (checkMonthFromUser(month) == true) {
            testMonth = true;
        } else {
            testMonth = false;
            return false;;
        }
    } else {
        testMonth = false;
        return false;;
    }

    if (checkIfFigureFrom0To9ASCII(day) == true) {
        if (checkDayFromUser(day, month, year) == true) {
            testDay = true;
        } else {
            testDay = false;
            return false;;
        }
    } else {
        testDay = false;
        return false;;
    }

    if(testYear == true && testMonth == true && testDay == true) {
        return true;
    } else {
        return false;
    }
}

bool SupportingMethods::checkYearFromUser(string year) {
    if (stoi(year) >= 2000 && stoi(year) <= stoi(getPresentYear())) {
        return true;
    } else {
        cout<<"Wrong year. Should be from 2000 to "<<getPresentYear()<<"."<<endl;
        return false;
    }
}

bool SupportingMethods::checkMonthFromUser(string month) {
    if (stoi(month) >= 1 && stoi(month) <= 12) {
        return true;
    } else {
        cout<<"Wrong month. Should be from 1 to 12."<<endl;
        return false;
    }
}

bool SupportingMethods::checkDayFromUser(string day, string month, string year) {
    if (stoi(day) >= 1 && stoi(day) <= stoi(howManyDaysInMonth(month, year))) {
        return true;
    } else {
        cout<<"Wrong day. Should be from 1 to "<<stoi(howManyDaysInMonth(month, year))<<"."<<endl;
        return false;
    }
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
        cout << "Only one sign. Try again..." << endl;
    }
    return sign;
}

bool SupportingMethods::checkIfFigureFrom0To9ASCII(string word) {
    int ASCII = NULL;
    for (int i=0; i<word.length(); i++) {
        ASCII = (int)word[i];
        if (ASCII >= 48 && ASCII <= 57) {
            continue;
        } else {
            cout<<"This is not a figure"<<endl;
            return false;
        }
    }
    return true;
}
