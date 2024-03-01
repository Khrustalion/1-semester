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
		return find(root->right,val);
	}
}

void preorder(Node* root) {
	if (root != nullptr) {
		std::cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
}



int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	long long n; std::cin >> n;
	std::string val;
	long long answer = 0;
	Node* root = nullptr;
	

	for (long long i = 0; i < n; ++i) {
		std::cin >> val;
		if (!find(root, val)) {
			root = insert(root, val);
		}
		else {
			uint8_t* count_arr = new uint8_t[257]{ 0 };
			long long n1 = val.length();
			for (long long i = 0; i < val.size(); ++i) {
				if (count_arr[val[i]] == 0) {
					++count_arr[val[i]];
					++answer;
				}
			}
		}
	}
	//preorder(root);
	//std::cout << '\n';
	std::cout << answer;
	return 0;
}