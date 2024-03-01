#include <iostream>

struct Node {
	int val;
	int min;
	int max;
	int sum;
	Node* parent;
	Node* left;
	Node* right;

	Node(Node* parent) : val{ 0 }, parent{ parent }, left{ nullptr }, right{ nullptr } {}
	Node(int val, Node* parent) : val{ val }, parent{ parent }, left{ nullptr }, right{ nullptr } {}
};

void preorder(Node* root) {
	if (root != nullptr) {
		std::cout << (int)root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	int n; std::cin >> n;
	Node* root = new Node(n, nullptr);
	Node* current = root;
	char ch; std::cin >> ch;
	while (ch != 's') {
		if (std::isdigit(ch)) {
			current->val = ch - '0';
		}
		else if (ch == 'l') {
			if (current->left == nullptr) {
				current->left = new Node(current);
				current = current->left;
			}
			else {
				current = current->left;
			}
		}
		else if (ch == 'r') {
			if (current->right == nullptr) {
				current->right = new Node(current);
				current = current->right;
			}
			else {
				current = current->right;
			}
		}
		else if (ch == 'u') {
			current = current->parent;
		}
		std::cin >> ch;
	}
	preorder(root);
	return 0;
}