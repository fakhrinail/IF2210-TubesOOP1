#include "Player.hpp"
#include "Engimon.hpp"
#include <iostream>
using namespace std;

Player::Player(Engimon basic) {
    this->activeEngimon = basic;
    this->playerPosition.setX(0)
    this->playerPosition.setY(0);
    this->activeEngimonPos.setX(0);
    this->activeEngimonPos.setY(1);
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

void Player::manageActiveEngimon() {
    cout << "Active Engimon : \n";
    this->activeEngimon.showDetail();
    cout << endl;
    cout << "What are you going to do?\n";
    cout << "1. Change Engimon\n";
    cout << "2. Back\n";
    cout << "(choose the number)\n";
    int entry;
    while (true) {
        cout << "input : ";
        cin >> entry;
        if (entry == 1) {
            this->setActiveEngimon();
            break;
        }
        else if (entry == 2) {
            break;
        }
        else {
            cout << "Invalid Action\n";
        }
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
    cout << "Change successful\n";
}

void Player::callEngimon() {
	cout << "\n" << "List Engimon : \n";
	this->inventoryE.printItem();
	cout << "Choose the engimon number : \n";
	int choosenNum;
	cin >> choosenNum;
	Engimon choosenEngimon = new this->inventoryE.getItem(choosenNum);
	this->activeEngimon = choosenEngimon;
	cout << "Change successful\n";
}

void Player::printAllInventory() {
    cout << "List Item : \n";
    this->inventoryS.printItem();
    cout << "\n" << "List Engimon : \n";
    this->inventoryE.printItem();
}

void Player::useSkill(){
	cout << "\n" << "List Item : \n";
	this->inventoryS.printItem();
	cout << "Choose the item number : \n";
	int choosenNum;
	cin >> choosenNum;
	Skill choosenItem = new this->inventoryS.getItem(choosenNum);
	this->activeEngimon.learn(choosenItem);
}

void Player::showCommands(){
    cout << "Commands available : \n";
    cout << "1. W\n";
    cout << "2. A\n";
    cout << "3. S\n";
    cout << "4. D\n";
    cout << "5. Show Commands\n";
    cout << "6. Inventory and Details\n";
    cout << "7. Use Item\n";
    cout << "8. Manage Active Engimon\n";
    cout << "9. Breeding\n";
    cout << "10. Battle\n";
    cout << "11. Exit\n";
    cout << "(choose the number)\n";
}

void Player::doCommands(Maps& M const){
    int entry;
    while (true) {
        cout << "Enter your commands : ";
        cin >> entry;
        cout << endl;
        try {
            if (entry == 1){
                if (!M.isValid()) throw("Cant Go That Way");
                else this->w();
            } 
            else if (entry == 2){
				if (!M.isValid()) throw("Cant Go That Way");
				else this->a();
			}
			else if (entry == 3) {
				if (!M.isValid()) throw("Cant Go That Way");
				else this->s();
			}
			else if (entry == 4) {
				if (!M.isValid()) throw("Cant Go That Way");
				else this->d();
			}
            else if (entry == 5) {
                this->showCommands();
			}
            else if (entry == 6) {
                this->printAllInventory();
            }
			else if (entry == 7) {
				this->useSkill();
			}
			else if (entry == 8) {
				this->manageActiveEngimon();
			}
			else if (entry == 9) {
				this->breedingMenu();
			}
        }
    }
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
