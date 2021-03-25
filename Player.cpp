#include "PlayerMaps.hpp"
#include <bits/stdc++.h>
using namespace std;

Player::Player(Engimon basic): playerPosition(), activeEngimonPos(0,1), inventoryE(), inventoryS() {
    this->activeEngimon = basic;
}

Player::~Player() {}

void Player::w() {
    this->activeEngimonPos = this->playerPosition;
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
    Engimon choosenEngimon = this->inventoryE.getItem(choosenNum-1);
    this->inventoryE.addItem(this->activeEngimon);
    this->activeEngimon = choosenEngimon;
    cout << "Change successful\n";
}

void Player::callEngimon() {
    cout << "Your active engimon is dead\n";
	cout << "\n" << "List Engimon : \n";
	this->inventoryE.printItem();
	cout << "Choose the engimon number : \n";
	int choosenNum;
	cin >> choosenNum;
	this->activeEngimon = this->inventoryE.getItem(choosenNum);
	cout  << "Change successful\n";
}

void Player::printAllInventory() {
    cout << "List Item : \n";
    this->inventoryS.printItem();
    cout << "\n" << "List Engimon : \n";
    this->inventoryE.printItem();
    cout << endl;
}

void Player::detailsMenu() {
    this->printAllInventory();
    int entry;
    pair<char, int> codeEntry;
    while (true) {
		cout << "Choose action : \n";
		cout << "1. Inventory Details\n";
		cout << "2. Show Inventory Again\n";
		cout << "3. Back\n";
		cout << "(choose the number)\n";
        cout << "Command : ";
        cin >> entry;
        if (entry == 1) {
            cout << "Entry code : \n";
            cout << "Engimon/Skill (input E/S) :";
            cin >> codeEntry.first;
            cout << "\n" << "Item number : ";
            cin >> codeEntry.second;
            cout << endl;
            if (codeEntry.first == 'E') {
                this->inventoryE.showDetail(codeEntry.second-1);
            }
            else if (codeEntry.first == 'S') {
                this->inventoryS.showDetail(codeEntry.second-1);
            }
            else {
                cout << "Invalid code\n";
            }
        }
        else if (entry == 2) {
            this->printAllInventory();
        } else if (entry == 3) break;
        else
        {
            cout << "Invalid command\n";
        }
    }    
}

void Player::useSkill(){
	cout << "\n" << "List Item : \n";
	this->inventoryS.printItem();
	cout << "Choose the item number : \n";
	int choosenNum;
	cin >> choosenNum;
	Skill choosenItem = this->inventoryS.getItem(choosenNum-1);
	this->activeEngimon.learnSkill(choosenItem);
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
    Engimon parent1;
    Engimon parent2;
    if (entry1 == 0) {
        parent1 = this->activeEngimon;
    }
    else {
        parent1 = this->inventoryE.getItem(entry1-1);
        if (entry2 > entry1) entry2--;
    }
	if (entry2 == 0) {
		parent2 = this->activeEngimon;
	}
	else {
		parent1 = this->inventoryE.getItem(entry2-1);
	}
    //Engimon child = breeding(parent1, parent2);
    /*if (child != NULL){
        this->inventoryE.addItem(child);
        if (entry1 != 0) this->inventoryE.addItem(parent1);
        if (entry2 != 0) this->inventoryE.addItem(parent2);
    }*/
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

void Player::addEngimon(Engimon e){
    try{
		this->inventoryE.addItem(e);
	}catch(char const* err){
		throw(err);
	}
}
void Player::addSkill(Skill s){
    try{
		this->inventoryS.addItem(s);
	}catch(char const* err){
		throw(err);
	}
}

void Player::doCommands(Maps& M){
    int round = 0;
    int entry;
    M.generateEngimon(this->getPlayerPosition(), this->getActiveEngimonPos(), 5);
    this->showCommands();
    while (true) {
        M.showMap(this->getPlayerPosition(), this->getActiveEngimonPos());
        cout << "Enter your commands : ";
        cin >> entry;
        cout << endl;
        try {
            round++;
            if (entry == 1){
                try{
                    this->w();
                }catch(const char* err){
                    cout << err << endl;
                }
            } 
            else if (entry == 2){
				try{
                    this->a();
                }catch(const char* err){
                    cout << err << endl;
                }
			}
			else if (entry == 3) {
				try{
                    this->s();
                }catch(const char* err){
                    cout << err << endl;
                }
			}
			else if (entry == 4) {
				try{
                    this->d();

                }catch(const char* err){
                    cout << err << endl;
                }
			}
            else if (entry == 5) {
                this->showCommands();
			}
            else if (entry == 6) {
                this->detailsMenu();
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
                M.generateEngimon(this->getPlayerPosition(), this->getActiveEngimonPos(), round);
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
/*
Engimon Player::breeding(Engimon& a, Engimon& b){
    return a + b;
}
*/

point Player::getPlayerPosition(){
	return this->playerPosition;
}

point Player::getActiveEngimonPos(){
	return this->activeEngimonPos;
}
