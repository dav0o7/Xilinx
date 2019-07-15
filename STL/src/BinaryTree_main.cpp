#include "STL/hdr/BinaryTree.hpp"

int main()
{
	BinaryTree BT;
	BT.add(12);
	BT.add(23);
	BT.add(53);
	BT.add(16);
	BT.add(32);
	BT.find(16);
	BT.change_val(32,45);
	BT.remove(12);
	BT.find(12);
	return 0;
}
