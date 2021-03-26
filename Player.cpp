#include "PlayerMaps.hpp"
#include <bits/stdc++.h>
using namespace std;

Player::Player(Engimon basic): playerPosition(), activeEngimonPos(0,1), inventoryE(), inventoryS() {
    this->activeEngimon = basic;
}

Player::~Player() {}

void Player::manageActiveEngimon() {
    cout << "Active Engimon : \n";
    this->activeEngimon.showDetail();
    cout << endl;
    cout << "What are you going to do?\n";
    cout << "1. Change Engimon\n";
    cout << "2. Interact\n";
    cout << "3. Back\n";
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
            this->activeEngimon.interact();
		}
        else if (entry == 3) {
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
    if(choosenNum > this->inventoryE.getLastIdx() || choosenNum<=0){
        cout << "Please choose a valid index" << endl;
    }else{
        Engimon choosenEngimon = this->inventoryE.getItem(choosenNum-1);
        this->inventoryE.addItem(this->activeEngimon);
        this->activeEngimon = choosenEngimon;
        cout << "Change successful\n";
    }
}

void Player::callEngimon() {
    if(this->inventoryE.getLastIdx()==0){
        throw 0;
    }
    cout << "Your active engimon is dead\n";
	cout << "\n" << "List Engimon : \n";
	this->inventoryE.printItem();
	cout << "Choose the engimon number : \n";
	int choosenNum;
	cin >> choosenNum;
	this->activeEngimon = this->inventoryE.getItem(choosenNum-1);
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
                if(codeEntry.second > inventoryE.getLastIdx() || codeEntry.second <= 0){
                    cout << "Please enter valid index" << endl;
                }else{
                    this->inventoryE.showDetail(codeEntry.second-1);
                }
            }
            else if (codeEntry.first == 'S') {
                if(codeEntry.second > inventoryS.getLastIdx() || codeEntry.second <= 0){
                    cout << "Please enter valid index" << endl;
                }else{
                    this->inventoryS.showDetail(codeEntry.second-1);
                }
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
	int entry;
    while (true) {
        this->inventoryS.printItem();
        cout << "Choose action : \n";
        cout << "1. Use skill item\n";
        cout << "2. Back\n";
        cout << "(choose the number)\n";
        cout << "Command : ";
        cin >> entry;
        if (entry == 1) {
			cout << "Choose the item number : \n";
			int choosenNum;
			cin >> choosenNum;
            if(choosenNum>inventoryS.getLastIdx() || choosenNum <=0){
                cout << "Please enter existing index" << endl;
            }else{
                Skill choosenItem = this->inventoryS.getItem(choosenNum - 1);
                try{
                    this->activeEngimon.learnSkill(choosenItem);
                }catch(const char* err){
                    cout << err << endl;
                    this->inventoryS.addItem(choosenItem);
                }
            }
        }
        else if (entry == 2) {
            break;
        } 
        else {
            cout << "Invalid command\n";
        }
    }
	cout << "Choose the item number : \n";
}

void Player::breedingMenu(string name) {
    int entry;
	cout << "\n" << "List Engimon : \n";
    cout << this->activeEngimon.getName() << " (active)" << endl;
	this->inventoryE.printItem();
    while (true) {
		cout << "\n" << "Choose the engimon number for your active engimon's mating partner: ";
		cin >> entry;
        if(entry<=0 || entry>inventoryE.getLastIdx()){
            cout << "Please enter a valid index." << endl;
        }else{
            break;
        }
    }
    Engimon partner =  this->inventoryE.getItem(entry-1);
    try{
        Engimon child = this->activeEngimon + partner;
        child.setName(name);
        this->inventoryE.addItem(child);
    }catch(const char* err){
        cout << err << endl;
    }
    this->inventoryE.addItem(partner);
}

void Player::showCommands(){
    cout << "Commands available : \n";
    cout << "1. (W)\n";
    cout << "2. (A)\n";
    cout << "3. (S)\n";
    cout << "4. (D)\n";
    cout << "5. Show (Commands)\n";
    cout << "6. (Inventory) and Details\n";
    cout << "7. Use Skill (Item)\n";
    cout << "8. (Manage) Active Engimon\n";
    cout << "9. (Breeding)\n";
    cout << "10. (Battle)\n";
    cout << "11. (Exit)\n";
    cout << "(type the word in parenthesis, with/out capital)\n";
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
    int round = 1;
    string entry;
    for(int i=0; i<M.getTotalEngimonSpawned(); i++){
        M.generateEngimon(this->getPlayerPosition(), this->getActiveEngimonPos(), 50);
    }
    M.showMap(this->getPlayerPosition(), this->getActiveEngimonPos(), round);
    while (true) {
        this->showCommands();
        cout << "Enter your commands : " << endl;
        cin >> entry;
        cout << endl;
        try {
            if(entry.length() == 1){
                //pasti gerak
                int shiftx = 0;
                int shifty = 0;
                if (entry == "W" || entry == "w"){
                    shiftx--;
                } 
                else if (entry == "A" || entry == "a"){
                    shifty--;
                }
                else if (entry == "S" || entry == "s") {
                    shiftx++;
                }
                else if (entry == "D" || entry == "d") {
                    shifty++;
                }else{
                    throw("Invalid command");
                }
                point toMove(this->playerPosition.getX()+shiftx, this->playerPosition.getY()+shifty);
                
                
                try{
                    M.showMap(toMove, this->playerPosition, round);
                    this->activeEngimonPos = this->playerPosition;
                    this->playerPosition = toMove;
                }catch(const char* err){
                    cout << err << endl;
                    M.showMap(this->getPlayerPosition(), this->getActiveEngimonPos(), round);
                }
                round++;
            }else{
                if (entry == "Commands" || entry == "commands") {
                    this->showCommands();
                }
                else if (entry == "Inventory" || entry == "inventory") {
                    this->detailsMenu();
                }
                else if (entry == "Item" || entry == "item") {
                    this->useSkill();
                }
                else if (entry == "Manage" || entry == "manage") {
                    this->manageActiveEngimon();
                }
                else if (entry == "Breeding" || entry == "breeding") {
                    if(InventoryParent::totalLoad == InventoryParent::maxCapacity){
                        cout << "Tolong bertanggung jawab dan ikuti KB (inventory full)" << endl;
                        cout << "Anda tidak bisa asal buat anak kalau ga mampu besarin" << endl;
                    }else{
                        cout << "Namakan anak anda mau siapa: " << endl;
                        string name;
                        cin >> name;
                        this->breedingMenu(name);
                    }
                }
                else if (entry == "Battle" || entry == "battle") {
                    try{
                        this->battle(M);
                    }catch(int nol){
                        cout << "Game over" << endl;
                        break;
                    }
                }
                else if (entry == "Exit" || entry == "exit") {
                    break;
                } else {
                    throw("Invalid command");
                }
                M.showMap(this->getPlayerPosition(), this->getActiveEngimonPos(), round);
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
