#include "SupportingMethods.h"

 string SupportingMethods::uploadLine(){
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

string SupportingMethods::getPresentDateString() {
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


