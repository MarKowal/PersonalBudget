#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <ctime>

using namespace std;

class SupportingMethods {

public:
    SupportingMethods(){};
    static string uploadLine();
    static string changeCommaToDot(string number);
    static string getPresentDateString();
    static string getPresentYear();
};

#endif
