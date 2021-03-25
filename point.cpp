//
// Created by abida on 23/03/2021.
//

#include "point.h"
#include <cstdlib>

int point::getX() const {
    return x;
}

void point::setX(int x) {
    point::x = x;
}

int point::getY() const {
    return y;
}

void point::setY(int y) {
    point::y = y;
}

point::point(int x, int y) {
    setX(x);
    setY(y);
}

point::~point() {

}

point::point(const point& p) {
	this->x = p.x;
	this->y = p.y;
}

point& point::operator=(const point& p) {
	this->x = p.x;
	this->y = p.y;
	return *this;
}

point::point(){
    x=0;y=0;
}

void point::randomPoint(int maxX, int maxY){
    x = rand() % (maxX+1);
    y = rand() % (maxY+1);
}

bool point::operator==(const point & p2){
    return this->x==p2.getX() && this->y==p2.getY();
}
