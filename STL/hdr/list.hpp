#include <iostream>
using type = int;

class listMember {
private:
	type value;
	listMember* prev;
	listMember* next;

public:
	listMember();
	listMember(type value);
	listMember(type value, listMember* prev, listMember* next);
	type getValue();
	listMember* getPrev();
	listMember* getNext();
	void setValue(type value);
	void setPrev(listMember* lis);
	void setNext(listMember* lis);
};

class list {
private:
	listMember* list_arr;
	int size;
public:
	list();
	list(int size);
	int getsize();
	void add(type value);
	void change(int index, type value);
	int find(type value);
	void remove (int index);
	void print();
};	

