#include <iostream>
using type = int;

class vector {
private:
	int size;
	type* vec;
public:
	vector();
	vector(int);
	int getsize();
	void push_back(type);
	void pop_back();
	void add(int, type);
	void remove(int);
	int find(type);
	void change(int, type);
	void print();
};
