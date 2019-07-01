#include <iostream>
#include <cassert>

using type = int;

class vector {
private:
	int size;
	type* vec;

public:
	
	vector() {
		size = 0;
		vec = new type[0];
	}

	vector(int size) {
		this->size = size;
		vec = new type[size];
	}

	int getsize() {
		return size;
	}

	void push_back(type value) {
		type* temp = new type[size + 1];
		std::copy(vec, vec + size, temp);
		delete[] vec;
		vec = temp;
		vec[size] = value;
		++size;
	}

	void pop_back() {
		assert(size != 0);
		--size;
		type* temp = new type[size - 1];
		std::copy(vec, vec + size, temp);
		delete[] vec;
		vec = temp;
		
	}

	void add(int index, type value) {
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

	void remove(int index) {
		assert(index < size);
		for (int i = index; i < size-1; i++) {
			vec[i] = vec[i + 1];
		}
		--size;
		type* temp = new type[size];
		std::copy(vec, vec + size, temp);
//		delete[] vec;	error
		vec = temp;
	}

	int find(type value) {
		for (int i = 0; i < size; ++i) {
			if (vec[i] == value)
				return i;
		}
		return size;
	}

	void change(int index, type value) {
		assert(index < size);
		vec[index] = value;
	}

	void print() {
		for (int i = 0; i < size; ++i) {
			std::cout << vec[i] << " ";
		}
		std::cout << "\n";
	}
};

int main() {
	//vector v;
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//v.push_back(50);
	//v.add(0, 0);
	//v.change(3, 29);
	//if (v.find(20) != v.getsize())
	//{
	//	std::cout << "Exists !\n";
	//}
	//v.pop_back();

	//v.remove(1);

	//v.print();
	return 0;
}
