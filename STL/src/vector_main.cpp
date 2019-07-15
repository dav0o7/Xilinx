#include "STL/hdr/vector.hpp"

int main() {
	vector v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.add(0, 0);
	v.change(3, 29);
	if (v.find(20) != v.getsize())
	{
		std::cout << "Exists !\n";
	}
	v.pop_back();
	v.remove(1);
	v.print();
	return 0;
}
