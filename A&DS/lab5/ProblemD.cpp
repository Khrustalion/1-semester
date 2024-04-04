#include <iostream>
#include <vector>

struct Node {
	long long val;
	Node* left_child;
	Node* right_child;

	Node(long long val) : val{ val }, left_child { nullptr }, right_child{ nullptr } {}
};

Node* insert(Node* root, long long val) {
	if (root == nullptr) {
		root = new Node(val);
		return root;
	}
	if (val < root->val) {
		root->left_child = insert(root->left_child, val);
	}
	else if (val > root->val) {
		root->right_child = insert(root->right_child, val);
	}
	return root;
}

Node* find(Node* root, long long val) {
	if (root->val > val) {
		if (root->left_child == nullptr) {
			return root;
		}
		return find(root->left_child, val);
	}
	else if (root->val < val) {
		if (root->right_child == nullptr) {
			return root;
		}
		return find(root->right_child, val);
	}
	return nullptr;
}

Node* CreateBST(long long* preorder, long long n) {
	Node* root = new Node(preorder[0]);
	Node* current = root;
	Node* tmp;

	for (long long i = 1; i < n; ++i) {
		if (preorder[i] < current->val) {
			current->left_child = new Node(preorder[i]);
			current = current->left_child;
		}
		else {
			tmp = find(root, preorder[i]);
			if (tmp != nullptr && tmp->val > preorder[i]) {
				tmp->left_child = new Node(preorder[i]);
				current = tmp->left_child;
			}
			else if (tmp != nullptr && tmp->val < preorder[i]){
				tmp->right_child = new Node(preorder[i]);
				current = tmp->right_child;
			}
		}
	}
	return root;
}

void preorder(Node* root) {
	if (root != nullptr) {
		std::cout << root->val << " ";
		preorder(root->left_child);
		preorder(root->right_child);
	}
}

long long bfs(Node* root, long long k) {
	if (root == nullptr) {
		return 0;
	}
	
	if (k != 0) --k;
	//std::cout << root->val << ", k = " << k << '\n';
	if (k == 0) {
		std::cout << root->val << " ";
	}
	k = std::max(bfs(root->right_child, k) + 1, k);
	k = std::max(bfs(root->left_child, k) + 1, k);
	
	return k;
}



int main() {
	long long n; std::cin >> n;
	long long num;
	Node* root = nullptr;
	for (long long i = 0; i < n; ++i) {
		std::cin >> num;
		root = insert(root, num);
	}
	bfs(root, 0);
	return 0;
}