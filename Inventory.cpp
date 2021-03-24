#include "Inventory.hpp"

Inventory::maxCapacity = 30;
Inventory::totalLoad = 0;

Inventory::Inventory(){
	this->nbItems = 0;
	this->items = new pair<T, int>[maxCapacity];
}

Inventory::~Inventory(){
	delete[] items;
}

int Inventory::isExist(T item){
	for (int i = 0; i < this->maxCapacity; i++) {
		if (this->items[i]->first == item) {
			return i;
		}
	}
	return -1;
}

int Inventory::getLastIdx() {
	int it = 0;
	while (this->items[i].second != 0) {
		it++;
	}
	return it;
}

void Inventory::addItem(T item){
	if (totalLoad == maxCapacity){
		throw("Inventory is full");
	}
	if (isExist(item) != -1){
		this->items[this->isExist(item)]->second++;
	} else{
		this->items[this->getLastIdx()]->first == item;
		this->items[this->getLastIdx()]->second++;
	}
	this->nbItems++;
	totalLoad++;
}

void Inventory::printItem() {
	for (int i = 0; i < this->nbItems; i++){
		cout << i+1 << ". " << this->items->first.getName() << " : " << this->items->second << endl;
	}
}

void Inventory::removeItem(int idx){
	if (this->items[idx].second > 1){
		this->items[idx].second--;
	} else {
		delete this->items[idx];
	}

	for (int i = idx; i < this->nbItems; i++){
		this->items[i] = this->items[i+1]
	}
}

T Inventory::getItem(int idx){
	T take = new T(this->items[idx].first);
	this->removeItem(idx);
	return T;
}