#include <iostream>
using type = int;

class BTNode {
private:
	type data;
	BTNode* Left_Node;
	BTNode* Right_Node;
public:

	BTNode();
	BTNode(type data, BTNode* Left, BTNode* Right);
	BTNode* get_left();
	BTNode* get_right();
	type get_data(); 
	void set_left(BTNode* node);
	void set_right(BTNode* node);
	void set_data(type value); 
};

class BinaryTree {
private:
	BTNode* nodes;
	int size;
public:

	BinaryTree();
	BinaryTree(int size);
	type getValue(int index);
	BTNode* add (type value);
	BTNode* find(type value);
	BTNode* change_val(type value, type to);
	BTNode* change_ind(int index, type to);
	BTNode* remove(type value);
};

