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
