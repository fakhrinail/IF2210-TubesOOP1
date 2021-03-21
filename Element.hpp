#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <bits/stdc++.h>

class Element {
protected:
    static float advantageChart[5][5];
    int elementID;
    char* elementName;
public:
    //4 Sekawan
    Element();//Bisa jadi disimpan dalam array
    Element(int ID, char* name);
    ~Element();
    //Getters
    int getElementID() const;
    char* getElementName() const;
    //Methods
    float getAdvantage(const Element& toCompare) const;
};

#endif