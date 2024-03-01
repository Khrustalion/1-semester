#include <iostream>
#include <string>

struct Node {
	long long val;
	Node* left;
	Node* right;
	long long height = 1;

	Node(long long val) : val{ val }, left{ nullptr }, right{ nullptr } {}
	Node(long long val, Node* left, Node* right) : val{ val }, left{ left }, right{ right } {}
};

long long getHeight(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return root->height;
}

long long correctionHeight(Node* root) {
	return std::max(getHeight(root->right), getHeight(root->left)) + 1;
}

long long findDiff(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return getHeight(root->right) - getHeight(root->left);
}

Node* leftRotation(Node* root) {
	Node* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	tmp->height = correctionHeight(tmp);
	root->height = correctionHeight(root);
	return tmp;
}

Node* rightRotation(Node* root) {
	Node* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	tmp->height = correctionHeight(tmp);
	root->height = correctionHeight(root);
	return tmp;
}

Node* bigLeftRotation(Node* root) {
	root->right = rightRotation(root->right);
	return leftRotation(root);
}

Node* bigRightRotation(Node* root) {
	root->left = leftRotation(root->left);
	return rightRotation(root);
}

Node* rotation(Node* root) {
	if (findDiff(root) == 2) {
		if (findDiff(root->right) < 0) {
			return bigLeftRotation(root);
		}
		else {
			return leftRotation(root);
		}
	}
	else if (findDiff(root) == -2) {
		if (findDiff(root->left) >= 0) {
			return bigRightRotation(root);
		}
		else {
			return rightRotation(root);
		}
	}
	return root;
}

Node* insert(Node* root, long long val) {
	if (root == nullptr) {
		Node* new_root = new Node(val);
		return new_root;
	}
	else if (val < root->val) {
		root->left = insert(root->left, val);
	}
	else if (val > root->val) {
		root->right = insert(root->right, val);
	}
	root->height = correctionHeight(root);
	root = rotation(root);
	return root;
}

Node* minimum(Node* root) {
	if (root->left == nullptr) {
		return root;
	}
	return minimum(root->left);
}

Node* maximum(Node* root) {
	if (root->right == nullptr) {
		return root;
	}
	return maximum(root->right);
}

Node* del(Node* root, long long x) {
	if (root == nullptr) {
		return root;
	}

	if (root->val < x) {
		root->right = del(root->right, x);
	}
	else if (root->val > x) {
		root->left = del(root->left, x);
	}

	else if (root->left != nullptr && root->right != nullptr) {
		root = minimum(root->right);
		root->right = del(root->right, root->val);
	}
	else {
		if (root->left != nullptr) {
			Node* child_left = root->left;
			child_left->height = correctionHeight(child_left);
			child_left = rotation(child_left);
			delete root;
			return child_left;
		}
		else if (root->right != nullptr) {
			Node* child_right = root->right;
			child_right->height = correctionHeight(child_right);
			child_right = rotation(child_right);
			delete root;
			return child_right;
		}
		return nullptr;

	}

	root->height = correctionHeight(root);

	return rotation(root);
}

bool find(Node* root, long long val) {
	if (root == nullptr) {
		return false;
	}
	if (val == root->val) {
		return true;
	}
	if (val < root->val) {
		return find(root->left, val);
	}
	else {
		return find(root->right, val);
	}
}

void preorder(Node* root) {
	if (root != nullptr) {
		std::cout << root->val << ":" << getHeight(root->left) << "|" << getHeight(root->right) << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	int n; std::cin >> n;
	char action;
	int x;
	Node* root = nullptr;

	for (int i = 0; i < n; ++i) {
		std::cin >> action;
		std::cin >> x;
		if (action == 'A') {
			root = insert(root, x);
			std::cout << findDiff(root) << '\n';
		}
		else if (action == 'D') {
			root = del(root, x);
			std::cout << findDiff(root) << '\n';
		}
		else if (action == 'C') {
			std::cout << (find(root, x) ? "Y" : "N") << '\n';
		}
		preorder(root);
	}
	return 0;
}