#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <iostream>
using namespace std;

template <class	T>
class Inventory {
	private:
		static int maxCapacity;
		static int totalLoad;
		int nbItems;
		pair<T, int>* items;
	public:
		Inventory();
		~Inventory();
		int isExist(T item);
		int getLastIdx();
		void addItem(T item);
		void printItem();
		void removeItem(int idx);
		T getItem(int idx);
};