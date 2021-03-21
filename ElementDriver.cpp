#include "Element.hpp"
using namespace std;

Element Fire(0, "Fire");
Element Water(1, "Water");
Element Electric(2, "Electric");
Element Ground(3, "Ground");
Element Ice(4, "Ice");

int main(){
    cout << Fire.getAdvantage(Ground) << endl;
}