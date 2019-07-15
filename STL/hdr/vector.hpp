#include <iostream>
using type = int;

class vector {
private:
	int size;
	type* vec;
public:
	vector();
	vector(int size);
	int getsize();
	void push_back(type value);
	void pop_back();
	void add(int index, type value);
	void remove(int index);
	int find(type value);
	void change(int index, type value);
	void print();
};
