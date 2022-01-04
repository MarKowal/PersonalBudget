#include "SupportingMethods.h"

 string SupportingMethods::uploadLine(){
    string input = "";
    cin.clear();
    cin.sync();
    getline(cin, input);
    return input;
}
