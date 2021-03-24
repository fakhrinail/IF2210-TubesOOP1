#include "Inventory.hpp"

template <class T>
int Inventory<T>::maxCapacity = 30;
template <class T>
int Inventory<T>::totalLoad = 0;

template <class T>
Inventory<T>::Inventory(){
	this->nbItems = 0;
	this->items = new pair<T, int>[maxCapacity];
}
template <class T>
Inventory<T>::~Inventory(){
	delete[] items;
}

template <class T>
int Inventory<T>::isExist(T item){
	for (int i = 0; i < this->maxCapacity; i++) {
		if (this->items[i].first == item) {
			return i;
		}
	}
	return -1;
}

template <class T>
int Inventory<T>::getLastIdx() {
	int it = 0;
	while (this->items[it].second != 0) {
		it++;
	}
	return it;
}

template <class T>
void Inventory<T>::addItem(T item){
	if (totalLoad == maxCapacity){
		throw("Inventory is full");
	}
	if (isExist(item) != -1){
		this->items[this->isExist(item)].second++;
	} else{
		this->items[this->getLastIdx()].first = item;
		this->items[this->getLastIdx()].second++;
	}
	this->nbItems++;
	totalLoad++;
}

template <class T>
void Inventory<T>::printItem() {
	int lastIdx = this->getLastIdx();
	if(lastIdx == 0){
		cout << "Kosong bro" << endl;
	}else{
		for (int i = 0; i < lastIdx; i++){
			cout << i+1 << ". " << this->items[i].first << " : " << this->items[i].second << endl;
		}
	}
}

template <class T>
void Inventory<T>::removeItem(int idx){
	idx--;
	if (this->items[idx].second > 1){
		this->items[idx].second--;
	}else{
		int lastIdx = this->getLastIdx();
		for (int i = idx; i < lastIdx; i++){
			this->items[i] = this->items[i+1];
		}
	}
	totalLoad--;
	this->nbItems--;
}
template <class T>
T Inventory<T>::getItem(int idx){
	T take = new T(this->items[idx].first);
	this->removeItem(idx);
	return take;
}