#include <iostream>
using type = int;

class BTNode {
private:
	type data;
	BTNode* Left_Node;
	BTNode* Right_Node;
public:

	BTNode();
	BTNode(type, BTNode*, BTNode*);
	BTNode* get_left();
	BTNode* get_right();
	type get_data(); 
	void set_left(BTNode*);
	void set_right(BTNode*);
	void set_data(type); 
};

class BinaryTree {
private:
	BTNode* nodes;
	int size;
public:

	BinaryTree();
	BinaryTree(int);
	type getValue(int);
	BTNode* add (type);
	BTNode* find(type);
	BTNode* change_val(type, type);
	BTNode* change_ind(int, type);
	BTNode* remove(type);
};

