#include <iostream>
#include <vector>

struct Node {
	int val;
	Node* right_child;
	Node* left_child;
	Node* parent;

	Node(int val, Node* parent) : val{ val }, parent{ parent }, right_child { nullptr }, left_child{ nullptr } {}
};

Node* maximum(Node* root) {
	if (root->right_child == nullptr) {
		return root;
	}
	return maximum(root->right_child);
}

Node* find(Node* root, long long val) {
	if (root->val > val) {
		if (root->left_child == nullptr) {
			return root;
		}
		return find(root->left_child, val);
	}
	else {
		if (root->right_child == nullptr) {
			return root;
		}
		return find(root->right_child, val);
	}
}


Node* CreateBST(long long* preorder, long long n) {
	Node* root = new Node(preorder[0], nullptr);
	Node* current = root;
	std::vector<Node*> stack;
	stack.push_back(root);

	for (long long i = 1; i < n; ++i) {
		if (preorder[i] < current->val) {
			current->left_child = new Node(preorder[i], current);
			current = current->left_child;
			stack.push_back(current);
		}
		else {
			int n_ = stack.size();
			while (n_ > 0 && stack[n_ - 1]->val <= preorder[i]) {
				current = stack[--n_];
				stack.pop_back();
			}
			current->right_child = new Node(preorder[i], current);
			current = current->right_child;
			stack.push_back(current);
		}
	}
	return root;
}

int ino = -1;
int posto = -1;

bool dfs(Node* root, long long* inorder, long long* postorder) {
	if (root != nullptr) {
		bool result = dfs(root->left_child, inorder, postorder);
		if (inorder[++ino] != root->val || result == false) {
			return false;
		}
		result &= dfs(root->right_child, inorder, postorder);
		if (postorder[++posto] != root->val) {
			return false;
		}
		return result;
	}
	return true;
}

int main() {
	int n; std::cin >> n;
	long long* preorder = new long long[n];
	long long* inorder = new long long[n];
	long long* postorder = new long long[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> preorder[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> inorder[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> postorder[i];
	}
	Node* root = CreateBST(preorder, n);
	std::cout << (dfs(root, inorder, postorder) ? "YES" : "NO");
	return 0;
}