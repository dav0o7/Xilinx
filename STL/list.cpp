#include <iostream>
#include <cassert>

using type = int;

class listMember {
private:
	type value;
	listMember* prev;
	listMember* next;

public:
	listMember() {
		value = 0;
		prev = NULL;
		next = NULL;
	}

	listMember(type value) {
		this->value = value;
		prev = NULL; 
		next = NULL;
	}

	listMember(type value, listMember* prev, listMember* next) {
		this->value = value;
		this->next = next;
		this->prev = prev;
	}

	type getValue() {
		return value;
	}

	listMember* getPrev() {
		return prev;
	}

	listMember* getNext() {
		return next;
	}

	void setValue(type value) {
		this->value = value;
	}

	void setPrev(listMember* lis) {
		prev = lis;
	}

	void setNext(listMember* lis) {
		next = lis;
	}
};

class list {
private:
	listMember* list_arr;
	int size;
public:
	list() {
		size = 0;
		list_arr = new listMember[0];
	}

	list(int size) {
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

	int getsize() {
		return size;
	}

	void add(type value) {
		listMember lis(value, &list_arr[size - 1], NULL);
		listMember* temp = new listMember[size + 1];
		std::copy(list_arr, list_arr + size, temp);
		delete[] list_arr;
		list_arr = temp;
		list_arr[size - 1].setNext(&lis) ;
		list_arr[size] = lis;
		size++;
	}

	void change(int index, type value) {
		assert(index < size);
		list_arr[index].setValue(value);
	}

	int find(type value) {
		for (int i = 0; i < size; ++i) {
			if (list_arr[i].getValue() == value)
				return i;
		}

		return size;
	}

	void remove (int index) {
		assert(index < size);
		for (int i = index; i < size - 1; ++i)
		{
			list_arr[i].setValue(list_arr[i + 1].getValue());
		}
		--size;
		listMember* temp = new listMember[size];
		std::copy(list_arr, list_arr + size, temp);
		delete[] list_arr;
		list_arr = temp;
	}

	void print() {
		for (int i = 0; i < size; ++i) {
			std::cout << list_arr[i].getValue() << " ";
		}
		std::cout << "\n";
	}
};

int main() {
	//list L (5);
	//L.add(18);
	//L.change(2, 23);
	//int ans = L.find(128);
	//if (ans != L.getsize()) {
	//	std::cout << "Found number in index [" << ans << "]\n";
	//}
	//else{
	//	std::cout << "No such number in List\n";
	//}
	//L.remove(0);
	//L.print();
	//return 0;
}
