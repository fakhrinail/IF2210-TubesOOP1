#include "Player.hpp"
#include "Engimon.hpp"
#include <iostream>
using namespace std;

Player::Player(Engimon basic) {
    this->activeEngimon = basic;
    this->playerPosition.setX(0)
    this->playerPosition.setY(0);
    this->activeEngimonPos.setX(0);
    this->activeEngimonPos.setY(0);
}

Player::~Player() {}

void Player::w() {
    if (!Map.empty(this->playerPosition.first + 1, this->playerPosition.second)){
        throw("Can't go that way");
    }
    this->playerPosition.first++;
    if (this->activeEngimonPos.first == this->playerPosition.first){
        this->activeEngimonPos.first--;
    } else {
        this->activeEngimonPos.first++;
    }
}

void Player::a() {
    if (!Map.empty(this->playerPosition.first, this->playerPosition.second - 1)){
        throw("Can't go that way");
    }
    this->playerPosition.second--;
	if (this->activeEngimonPos.second == this->playerPosition.second) {
		this->activeEngimonPos.second++;
	}
	else {
		this->activeEngimonPos.second--;
	}
}

void Player::s() {
    if (!Map.empty(this->playerPosition.first - 1, this->playerPosition.second)){
        throw("Can't go that way");
    }
    this->playerPosition.first--;
	if (this->activeEngimonPos.first == this->playerPosition.first) {
		this->activeEngimonPos.first++;
	}
	else {
		this->activeEngimonPos.first--;
	}
}

void Player::d() {
    if (!Map.empty(this->playerPosition.first, this->playerPosition.second + 1)){
        throw("Can't go that way");
    }
    this->playerPosition.second++;
	if (this->activeEngimonPos.second == this->playerPosition.second) {
		this->activeEngimonPos.second--;
	}
	else {
		this->activeEngimonPos.second++;
	}
}

void Player::setActiveEngimon(){
	cout << "\n" << "List Engimon : \n";
	this->inventoryE.printItem();
    cout << "Choose the engimon number : \n";
    int choosenNum;
    cin >> choosenNum;
    Engimon choosenEngimon = new this->inventoryE.getItem(choosenNum);
    this->inventoryE.addItem(this->activeEngimon);
    this->activeEngimon = choosenEngimon;
}

void Player::printAllInventory() {
    cout << "List Item : \n";
    this->inventoryS.printItem();
    cout << "\n" << "List Engimon : \n";
    this->inventoryE.printItem();
}

Engimon Player::getActiveEngimon(){
    return this->activeEngimon;
}

Engimon Player::breeding(Engimon a, Engimon b){
    return a + b;
}

pair<int, int> Player::getPlayerPosition(){
	pair<int, int> pos = new pair<int, int>;
	pos.first = this->playerPosition.first;
	pos.second = this->playerPosition.second;
	return pos;
}

pair<int,int> Player::getActiveEngimonPos(){
	pair<int, int> pos = new pair<int, int>;
	pos.first = this->activeEngimonPos.first;
	pos.second = this->activeEngimonPos.second;
	return pos;
}
