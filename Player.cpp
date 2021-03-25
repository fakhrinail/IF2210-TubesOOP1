#include "Player.hpp"
#include "Engimon.hpp"
#include <iostream>
using namespace std;

Player::Player(Engimon basic) {
    this->activeEngimon = basic;
    this->playerPosition = new point();
    this->activeEngimonPos = new point(0,1);
    this->inventoryE = new Inventory<Engimon>();
    this->inventoryS = new Inventory<Skill>();
}

Player::~Player() {}

void Player::w() {
    this->playerPosition.decrementX();
    if (this->activeEngimonPos.getX() == this->playerPosition.getX()){
        this->activeEngimonPos.incrementX();
    } else {
        this->activeEngimonPos.decrementX();
    }
}

void Player::a() {
    this->playerPosition.decrementY();
	if (this->activeEngimonPos.getY() == this->playerPosition.getY()) {
		this->activeEngimonPos.incrementY();
	}
	else {
		this->activeEngimonPos.decrementY();
	}
}

void Player::s() {
    this->playerPosition.incrementX();
	if (this->activeEngimonPos.getX() == this->playerPosition.getX()) {
		this->activeEngimonPos.decrementX();
	}
	else {
		this->activeEngimonPos.incrementX();
	}
}

void Player::d() {
    this->playerPosition.incrementY();
	if (this->activeEngimonPos.getY() == this->playerPosition.getY()) {
		this->activeEngimonPos.decrementY();
	}
	else {
		this->activeEngimonPos.incrementY();
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
    cout << "Your active engimon is dead\n";
	cout << "\n" << "List Engimon : \n";
	this->inventoryE.printItem();
	cout << "Choose the engimon number : ";
	int choosenNum;
	cin >> choosenNum;
	Engimon choosenEngimon = new this->inventoryE.getItem(choosenNum);
	this->activeEngimon = choosenEngimon;
	cout << "\n" << "Change successful\n";
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

void Player::breedingMenu() {
    int entry1;
    int entry2;
	cout << "\n" << "List Engimon : \n";
    cout << "0. " << this->activeEngimon.getName() << " (active)" << endl;
	this->inventoryE.printItem();
	cout << "Choose the engimon number for parent 1: ";
	cin >> entry1;
    while (true) {
		cout << "\n" << "Choose the engimon number for parent 2: ";
		cin >> entry2;
        if (entry2 == entry1) {
            cout << "Parent 1 and parent 2 must be different\n";
        } else break;
    }
	this->inventoryE.addItem(this->activeEngimon);
	this->activeEngimon = choosenEngimon;
	cout << "\n" << "Change successful\n";
    Engimon parent1;
    Engimon parent2;
    if (entry1 == 0) {
        parent1 = &this->activeEngimon;
    }
    else {
        parent1 = this->inventoryE.getItem(entry1);
        if (entry2 > entry1) entry2--;
    }
	if (entry2 == 0) {
		parent2 = &this->activeEngimon;
	}
	else {
		parent1 = this->inventoryE.getItem(entry2);
	}
    Engimon child = breeding(parent1, parent2);
    if (child != NULL){
        this->inventoryE.addItem(child);
        if (entry1 != 0) this->inventoryE.addItem(parent1);
        if (entry2 != 0) this->inventoryE.addItem(parent2);
    }
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
			else if (entry == 10) {
				this->battle(M);
			}
			else if (entry == 11) {
				break;
            } else {
                throw("Invalid command");
            }
        }
        catch (const char* err) {
            cout << err << endl;
        }
    }
    cout << "Thanks for playing~~" << endl;
}

Engimon Player::getActiveEngimon(){
    return this->activeEngimon;
}

Engimon& Player::breeding(Engimon& a, Engimon& b){
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
