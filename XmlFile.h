#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "Markup.h"



using namespace std;

class XmlFile {
    string NAME_OF_FILE;


public:
    XmlFile(string NAME_OF_FILE = "", CMarkup xml = NULL) {
        this -> NAME_OF_FILE = NAME_OF_FILE;
    };
    CMarkup xml;
    string getNAME_OF_FILE();
    void setNAME_OF_FILE(string newNAME_OF_FILE);


};

#endif
