#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <iostream>
#include "Skill.hpp"
using namespace std;

template <class	T>
class Inventory {
	private:
		static int maxCapacity;
		static int totalLoad;
		int nbItems;
		pair<T, int>* items;
	public:
		Inventory(){
			this->nbItems = 0;
			this->items = new pair<T, int>[maxCapacity];
		}
		~Inventory(){
			delete[] items;
		}
		int isExist(T item){
			for (int i = 0; i < this->maxCapacity; i++) {
				if (this->items[i].first == item) {
					return i;
				}
			}
			return -1;
		}
		int getLastIdx(){
			int it = 0;
			while (this->items[it].second != 0) {
				it++;
			}
			return it;
		}
		void addItem(T item){
			if (totalLoad == maxCapacity) {
				throw("Inventory is full");
			}
			if (isExist(item) != -1) {
				this->items[this->isExist(item)].second++;
			}
			else {
				this->items[this->getLastIdx()].first = item;
				this->items[this->getLastIdx()].second++;
			}
			this->nbItems++;
			totalLoad++;
		}
		void printItem(){
			int lastIdx = this->getLastIdx();
			if (lastIdx == 0) {
				cout << "It's empty" << endl;
			}
			else {
				for (int i = 0; i < lastIdx; i++) {
					cout << i + 1 << ". " << this->items[i].first << " : " << this->items[i].second << endl;
				}
			}
		}
		void removeItem(int idx){
			idx--;
			if (this->items[idx].second > 1) {
				this->items[idx].second--;
			}
			else {
				int lastIdx = this->getLastIdx();
				for (int i = idx; i < lastIdx; i++) {
					this->items[i] = this->items[i + 1];
				}
			}
			totalLoad--;
			this->nbItems--;
		}
		T getItem(int idx){
			T take = new T(this->items[idx].first);
			this->removeItem(idx);
			return take;
		}
};
#endif