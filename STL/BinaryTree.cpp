#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using type = int;

class BTNode {
private:
	type data;
	BTNode* Left_Node;
	BTNode* Right_Node;
public:

	BTNode() {
		data = 0;
		Left_Node = NULL;
		Right_Node = NULL;
	}

	BTNode(type data, BTNode* Left, BTNode* Right) {
		this->data = data;
		this->Left_Node = Left;
		this->Right_Node = Right;
	}

	BTNode* get_left() {
		return Left_Node;
	}

	BTNode* get_right() {
		return Right_Node;
	}

	type get_data() {
		return data;
	}

	void set_left(BTNode* node) {
		Left_Node = node;
	}

	void set_right(BTNode* node) {
		Right_Node = node;
	}

	void set_data(type value) {
		data = value;
	}
};

class BinaryTree {
private:
	BTNode* nodes;
	int size;
public:

	BinaryTree() {
		this->size = 0;
		nodes = new BTNode[0];
	}

	BinaryTree(int size) {
		this->size = size;
		nodes = new BTNode[size];
	}

	type getValue(int index) {
		assert(index < size);
		return nodes[index].get_data();
	}

	BTNode* add (type value) {
		BTNode* leaf = new BTNode();
		leaf->set_data(value);
		BTNode* temp = new BTNode[size + 1];
		std::copy(nodes, nodes + size, temp);
		delete[] nodes;
		nodes = temp;
		nodes[size] = *leaf;
		++size;
		if (size == 1) {
			return nodes;
		}

		BTNode* root = nodes;
		std::queue <BTNode*> test;
		test.push(root);

		while (!test.empty()) {
			BTNode* check = test.front();
			test.pop();
			if (check->get_left() == NULL) {
				check->set_left(leaf);
				break;
			}
			else {
				test.push(check->get_left());
			}
			if (check->get_right() == NULL) {
				check->set_right(leaf);
				break;
			}
			else {
				test.push(check->get_right());
			}
		}
		return nodes;
	}

	BTNode* find(type value) {
		assert(size > 0);
		
		for (int i = 0; i < size; ++i) {
			if (nodes[i].get_data() == value) {
				return &nodes[i];
			}
		}
		return NULL;
	}

	BTNode* remove(type value) {
		BTNode* root = nodes;
		assert(size > 0);
		assert(find(value) != NULL);

		if (root->get_left() == NULL && root->get_right() == NULL) {
			if (root->get_data() == value)
			{
				return NULL;
			}
			return root;
		}

		BTNode* rightest = root;

		while (rightest->get_right() != NULL) {
			rightest = rightest->get_right();
		}
		while (rightest->get_left() != NULL) {
			rightest = rightest->get_left();
			if (rightest->get_right() != NULL) {
				rightest = rightest->get_right();
			}
		}

		BTNode* del = find(value);

		if (del != NULL) {
			int temp = del->get_data();
			del->set_data(rightest->get_data());
			rightest->set_data(temp);
			rightest = NULL;
			--size;
			BTNode* tmp = new BTNode[size];
			std::copy(nodes, nodes + size, tmp);
			delete[] nodes;
			nodes = tmp;
		}

		return root;
	}

};

int main()
{
	BinaryTree BT;
	//BT.add(12);
	//BT.add(23);
	//BT.add(53);
	//BT.add(16);
	//BT.add(32);
	//BT.find(16);
	//BT.remove(12);
	//BT.find(12);
	return 0;
}
