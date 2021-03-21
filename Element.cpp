#include "Element.hpp"
using namespace std;

float Element::advantageChart[5][5] = { {1,0,1,0.5,2},
                                        {2,1,0,1,1},
                                        {1,2,1,0,1.5},
                                        {1.5,1,2,1,0},
                                        {0,1,0.5,2,1}};

Element::Element(){
    this->elementID = -1;
    this->elementName = new char[0];
}
Element::Element(int ID, char* name){
    this->elementID = ID;
    int len = strlen(name);
    this->elementName = new char[len];
    for(int i=0; i<len; i++){
        this->elementName[i] = name[i];
    }
}
Element::~Element(){
    delete[] this->elementName;
}

int Element::getElementID() const {
    return this->elementID;
}
char* Element::getElementName() const {
    return this->elementName;
}

float Element::getAdvantage(const Element& toCompare) const {
    return this->advantageChart[this->elementID][toCompare.elementID];
}