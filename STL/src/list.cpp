#include "STL/hdr/list.hpp"
#include <cassert>

listMember::listMember() {
	value = 0;
	prev = NULL;
	next = NULL;
}

listMember::listMember(type value) {
	this->value = value;
	prev = NULL; 
	next = NULL;
}

listMember::listMember(type value, listMember* prev, listMember* next) {
	this->value = value;
	this->next = next;
	this->prev = prev;
}

type listMember::getValue() {
	return value;
}

listMember* listMember::getPrev() {
	return prev;
}

listMember* listMember::getNext() {
	return next;
}

void listMember::setValue(type value) {
	this->value = value;
}

void listMember::setPrev(listMember* lis) {
	prev = lis;
}

void listMember::setNext(listMember* lis) {
	next = lis;
}

list::list() {
	size = 0;
	list_arr = new listMember[0];
}

list::list(int size) {
	this->size = size;
	list_arr = new listMember[size];
	for (int i = 0; i < size; ++i) {
		if (i == 0 && size == 1) {
			listMember lis(0);
			list_arr[i] = lis;
		}
		else if (i == 0) {
			listMember lis (0, NULL, &list_arr[i + 1]);
			list_arr[i] = lis;
		}
		else if (i == size - 1) {
			listMember lis(0, &list_arr[i - 1], NULL);
			list_arr[i] = lis;
		}
		else {
			listMember lis(0, &list_arr[i - 1], &list_arr[i + 1]);
			list_arr[i] = lis;
		}	
	}
}

int list::getsize() {
	return size;
}

void list::add(type value) {
	listMember lis(value, &list_arr[size - 1], NULL);
	listMember* temp = new listMember[size + 1];
	std::copy(list_arr, list_arr + size, temp);
	delete[] list_arr;
	list_arr = temp;
	list_arr[size - 1].setNext(&lis) ;
	list_arr[size] = lis;
	size++;
}

void list::change(int index, type value) {
	assert(index < size);
	list_arr[index].setValue(value);
}

int list::find(type value) {
	for (int i = 0; i < size; ++i) {
		if (list_arr[i].getValue() == value)
			return i;
	}

	return size;
}

void list::remove (int index) {
	assert(index < size);
	for (int i = index; i < size - 1; ++i){
		list_arr[i].setValue(list_arr[i + 1].getValue());
	}
	--size;
	listMember* temp = new listMember[size];
	std::copy(list_arr, list_arr + size, temp);
	delete[] list_arr;
	list_arr = temp;
}

void list::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << list_arr[i].getValue() << " ";
	}
	std::cout << "\n";
}
