#include "Element.hpp"
using namespace std;

float Element::advantageChart[6][6] = { {0,0,0,0,0,0},
                                        {0,1,0,1,0.5,2},
                                        {0,2,1,0,1,1},
                                        {0,1,2,1,0,1.5},
                                        {0,1.5,1,2,1,0},
                                        {0,0,1,0.5,2,1}};
string Element::elementNames[6] = {"None", "Fire", "Water", "Electric", "Ground", "Ice"};

Element::Element(){
    this->elementID = 0;
    this->elementName = "";
}
Element::Element(string name){
    this->elementName = name;
    if(name == "Fire"){
        this->elementID = 1;
    }else if(name == "Water"){
        this->elementID = 2;
    }else if(name == "Electric"){
        this->elementID = 3;
    }else if(name == "Ground"){
        this->elementID = 4;
    }else if(name == "Ice"){
        this->elementID = 5;
    }else{
        this->elementID = 0;
    }
}
Element::~Element(){
}

int Element::getElementID() const {
    return this->elementID;
}
string Element::getElementName() const {
    return this->elementName;
}

float Element::getAdvantage(const Element& toCompare) const {
    return this->advantageChart[this->elementID][toCompare.elementID];
}