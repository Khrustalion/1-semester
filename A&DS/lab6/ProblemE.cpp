#include <iostream>
#include <string>

struct Node {
	std::string val;
	Node* left;
	Node* right;
	long long height = 1;

	Node(std::string val) : val{ val }, left{ nullptr }, right{ nullptr } {}
	Node(std::string val, Node* left, Node* right) : val{ val }, left{ left }, right{ right } {}
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

Node* insert(Node* root, std::string val) {
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

bool find(Node* root, std::string val) {
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
		std::cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int count_ball(std::string name, Node* friend_first, Node* friend_second) {
	int ball1 = (find(friend_first, name) == 0) ? 1 : 0;
	int ball2 = (find(friend_second, name) == 0) ? 1 : 0;
	if ((ball1 == ball2) && ball1 == 1) {
		return 3;
	}
	else if ((ball1 == ball2) && ball1 == 0) {
		return 0;
	}
	return 1;
}

int dfs(Node* root, int count, Node* friend_first, Node* friend_second) {
	if (root == nullptr) {
		return count;
	}

	count += dfs(root->left, 0, friend_first, friend_second);
	count += dfs(root->right, 0, friend_first, friend_second);
	count += count_ball(root->val, friend_first, friend_second);
	return count;
}

int main() {
	int n; std::cin >> n;
	Node** friends = new Node * [3];
	std::string name;
	for (int i = 0; i < 3; ++i) {
		friends[i] = nullptr;
		for (int j = 0; j < n; ++j) {
			std::cin >> name;

			friends[i] = insert(friends[i], name);
		}
	}
	std::cout << dfs(friends[0], 0, friends[1], friends[2]) << " " << dfs(friends[1], 0, friends[0], friends[2]) << " " << dfs(friends[2], 0, friends[0], friends[1]);
	return 0;
}