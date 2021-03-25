#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <bits/stdc++.h>
using namespace std;

class Element {
protected:
    static float advantageChart[6][6];
    int elementID;
    string elementName;
public:
    //4 Sekawan
    Element();//Bisa jadi disimpan dalam array
    Element(string name);
    ~Element();
    //Getters
    int getElementID() const;
    string getElementName() const;
    //Methods
    float getAdvantage(const Element& toCompare) const;
};

#endif