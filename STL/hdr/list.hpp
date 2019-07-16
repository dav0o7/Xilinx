#include <iostream>
using type = int;

class listMember {
private:
	type value;
	listMember* prev;
	listMember* next;

public:
	listMember();
	listMember(type );
	listMember(type , listMember*, listMember*);
	type getValue();
	listMember* getPrev();
	listMember* getNext();
	void setValue(type);
	void setPrev(listMember*);
	void setNext(listMember*);
};

class list {
private:
	listMember* list_arr;
	int size;
public:
	list();
	list(int);
	int getsize();
	void add(type);
	void change(int, type);
	int find(type);
	void remove (int);
	void print();
};	

