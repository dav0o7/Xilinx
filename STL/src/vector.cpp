#include <cassert>
#include "STL/hdr/vector.hpp"

using type = int;

vector::vector() {
	size = 0;
	vec = new type[0];
}

vector::vector(int size) {
	this->size = size;
	vec = new type[size];
}

int vector::getsize() {
	return size;
}

void vector::push_back(type value) {
	type* temp = new type[size + 1];
	std::copy(vec, vec + size, temp);
	delete[] vec;
	vec = temp;
	vec[size] = value;
	++size;
}

void vector::pop_back() {
	assert(size != 0);
	--size;
	type* temp = new type[size - 1];
	std::copy(vec, vec + size, temp);
	delete[] vec;
	vec = temp;
	
}

void vector::add(int index, type value) {
	assert(index <= size);
	++size;
	type* temp = new type[size + 1];	
	std::copy(vec, vec + size - 1, temp);
	delete[] vec;
	vec = temp;
	for (int i = size - 2; i >= index; --i) {
		vec[i + 1] = vec[i];
	}
	vec[index] = value;
}

void vector::remove(int index) {
	assert(index < size);
	for (int i = index; i < size-1; i++) {
		vec[i] = vec[i + 1];
	}
	--size;
	type* temp = new type[size];
	std::copy(vec, vec + size, temp);
//	delete[] vec;	error
	vec = temp;
}

int vector::find(type value) {
	for (int i = 0; i < size; ++i) {
		if (vec[i] == value)
			return i;
	}
	return size;
}

void vector::change(int index, type value) {
	assert(index < size);
	vec[index] = value;
}

void vector::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

