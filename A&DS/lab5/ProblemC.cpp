#include <iostream>

long long glb = 0;
long long cnt = 0;

struct Node {
	long long val;
	Node* left_child;
	Node* right_child;
	int count_left;
	int count_right;

	Node(long long val) : val{ val }, left_child{ nullptr }, right_child{ nullptr }, count_left{ 0 }, count_right{ 0 } {}
};

Node* insert(Node* root, long long val) {
	if (root == nullptr) {
		root = new Node(val);
	}
	
	if (root->val < val) {
		root->right_child = insert(root->right_child, val);
		++root->count_right;
	}
	else if (root->val > val) {
		++root->count_left;
		root->left_child = insert(root->left_child, val);
	}
	return root;
}

Node* minimum(Node* root) {
	if (root->left_child == nullptr) {
		return root;
	}
	return minimum(root->left_child);
}

Node* maximum(Node* root) {
	if (root->right_child == nullptr) {
		return root;
	}
	return maximum(root->right_child);
}

Node* del(Node* root, long long x) {
	if (root == nullptr) {
		return root;
	}

	if (root->val < x) {
		--root->count_right;
		root->right_child = del(root->right_child, x);
	}
	else if (root->val > x) {
		--root->count_left;
		root->left_child = del(root->left_child, x);
	}

	else if (root->left_child != nullptr && root->right_child != nullptr) {
		root->val = minimum(root->right_child)->val;
		--root->count_right;
		root->right_child = del(root->right_child, root->val);
	}
	else {
		if (root->left_child != nullptr) {
			Node* child_left = root->left_child;
			delete root;
			return child_left;
		}
		else if (root->right_child != nullptr) {
			Node* child_right = root->right_child;
			delete root;
			return child_right;
		}
		else {
			root = nullptr;
		}
	}
	return root;
}

 Node* dfs(Node* root, int k) {
	 if (root == nullptr) {
		 return root;
	 }
	 if (root->count_right + 2 == k) {
		 return maximum(root->left_child);
	}
	 else if (root->count_right == k - 1) {
		 return root;
	 }
	 else if (root->count_right >= k) {
		 return dfs(root->right_child, k);
	 }
	 else if (root->count_right < k) {
		 return dfs(root->left_child, k - root->count_right - 1);
	 }
 }

 void preorder(Node* root) {
	 if (root != nullptr) {
		 std::cout << root->val << '\n';
		 preorder(root->left_child);
		 preorder(root->right_child);
	 }
 }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	long long n; std::cin >> n;
	long long action;
	long long val;
	Node* answer = nullptr;
	Node* root = nullptr;
	for (long long i = 0; i < n; ++i) {
		std::cin >> action >> val;
		if (action == 1) {
			root = insert(root, val);
		}
		else if (action == 0) {
			if (val <= root->count_left + root->count_right + 1) {
				answer = dfs(root, val);
				if (answer != nullptr) {
					std::cout << answer->val << '\n';
				}
			}
		}
		else if (action == -1) {
			root = del(root, val);
		}
		//preorder(root);
	}
	
	return 0;
}