#include "Element.hpp"
using namespace std;

Element Fire("Fire");
Element Water("Water");
Element Electric("Electric");
Element Ground("Ground");
Element Ice("Ice");

int main(){
    cout << Fire.getAdvantage(Ground) << endl;
    cout << Fire.getElementName() << endl;
}