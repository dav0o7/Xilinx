#include "STL/hdr/list.hpp"

int main() {
	list L (5);
	L.add(18);
	L.change(2, 23);
	int ans = L.find(128);
	if (ans != L.getsize()) {
		std::cout << "Found number in index [" << ans << "]\n";
	}
	else{
		std::cout << "No such number in List\n";
	}
	L.remove(0);
	L.print();
	return 0;
}
