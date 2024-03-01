#include <iostream>
#include <string>

struct Node {
	long long value;
	Node* left;
	Node* right;

	Node(long long value_) : value{ value_ }, left{ nullptr }, right{ nullptr } {}
	Node(long long value_, Node* left, Node* right) : value{ value_ }, left{ left }, right{ right } {}
};

Node* next(Node* root, long long x);

Node* minimum(Node* root);

Node* insert(Node* root, long long x) {
	if (root == nullptr) {
		Node* child = new Node(x);
		return child;
	}
	else if (x > root->value) {
		root->right = insert(root->right, x);
	}
	else if (x < root->value) {
		root->left = insert(root->left, x);
	}
	return root;
}

Node* exist(Node* root, long long x) {
	if (root == nullptr || root->value == x) {
		return root;
	}
	else if (x < root->value) {
		return exist(root->left, x);
	}
	return exist(root->right, x);
}

Node* del(Node* root, long long x) {
	if (root == nullptr) {
		return root;
	}

	if (root->value < x) {
		root->right = del(root->right, x);
	}
	else if (root->value > x) {
		root->left = del(root->left, x);
	}

	else if (root->left != nullptr && root->right != nullptr) {
		root->value = minimum(root->right)->value;
		root->right = del(root->right, root->value);
	}
	else {
		if (root->left != nullptr) {
			Node* child_left = root->left;
			delete root;
			return child_left;
		}
		else if (root->right != nullptr) {
			Node* child_right = root->right;
			delete root;
			return child_right;
		}
		else {
			root = nullptr;
		}
	}
	return root;
}

Node* maximum(Node* root) {
	if (root->right == nullptr) {
		return root;
	}
	return maximum(root->right);
}

Node* prev(Node* root, long long x) {
	Node* next = root;
	Node* prev = nullptr;
	while (next != nullptr) {
		if (next->value < x) {
			prev = next;
			next = next->right;
		}
		else {
			next = next->left;
		}
	}
	return prev;
}

Node* minimum(Node* root) {
	if (root->left == nullptr) {
		return root;
	}
	return minimum(root->left);
}

Node* next(Node* root, long long x) {
	Node* next = root;
	Node* res = nullptr;
	while (next != nullptr) {
		if (next->value > x) {
			res = next;
			next = next->left;
		}
		else {
			next = next->right;
		}
	}
	return res;
}

void preorder(Node* root) {
	if (root != nullptr) {
		std::cout << root->value << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	std::string action;
	long long n;
	Node* root = nullptr;
	while (std::cin >> action) {
		std::cin >> n;
		if (action == "insert") {
			root = insert(root, n);
		}
		else if (action == "delete") {
			root = del(root, n);
		}
		else if (action == "exists") {
			if (exist(root, n) == nullptr) {
				std::cout << "false";
			}
			else {
				std::cout << "true";
			}
			std::cout << '\n';
		}
		else if (action == "next") {
			if (next(root, n) == nullptr) {
				std::cout << "none" << '\n';
			}
			else {
				std::cout << next(root, n)->value << '\n';
			}
		}
		else if (action == "prev") {
			if (prev(root, n) == nullptr) {
				std::cout << "none" << '\n';
			}
			else {
				std::cout << prev(root, n)->value << '\n';
			}
		}
		//preorder(root);
	}
	return 0;
}