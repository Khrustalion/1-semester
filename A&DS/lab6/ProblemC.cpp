#include <iostream>
#include <list>

struct Node {
	int val;
	int count_right = -1;
	int count_left = -1;
	int right;
	int left;
	int dif = 0;

	Node(int val, int left, int right) : val{ val }, left{ left }, right{ right } {}
	};

int travelSet(Node** arr, int ind) {
	if (arr[ind]->count_right == -1) {
		if (arr[ind]->right != -1) {
			arr[ind]->count_right = travelSet(arr, arr[ind]->right);
		}
	}
	if (arr[ind]->count_left == -1) {
		if (arr[ind]->left != -1) {
			arr[ind]->count_left = travelSet(arr, arr[ind]->left);
		}
	}
	arr[ind]->dif = arr[ind]->count_right - arr[ind]->count_left;
	return std::max(arr[ind]->count_left, arr[ind]->count_right) + 1;
}

int SmallLeftTurn(Node** arr, int root) {
	int right_child = arr[root]->right;
	int tmp = arr[right_child]->left;
	arr[right_child]->left = root;
	arr[root]->right = tmp;
	return right_child;
}

int SmallRightTurn(Node** arr, int root) {
	int left_child = arr[root]->left;
	int tmp = arr[left_child]->right;
	arr[left_child]->right = root;
	arr[root]->left = tmp;
	return left_child;
}

int BigLeftTurn(Node** arr, int root) {
	int right_child = arr[root]->right;
	int right_left_child = arr[right_child]->left;
	int left = arr[right_left_child]->left;
	int right = arr[right_left_child]->right;
	arr[right_left_child]->right = right_child;
	arr[right_left_child]->left = root;
	arr[root]->right = left;
	arr[right_child]->left = right;
	return right_left_child;
}

int BigRightTurn(Node** arr, int root) {
	int left_child = arr[root]->left;
	int left_right_child = arr[left_child]->right;
	int right = arr[left_right_child]->right- 1;
	int left = arr[left_right_child]->left;
	arr[left_right_child]->left = left_child;
	arr[left_right_child]->right = root;
	arr[root]->left = right;
	arr[left_child]->right = left;
	return left_right_child;
}

void PrintBST(Node** arr, int n, int root) {
	std::list<int> queue;
	int size = 1;
	int k = 1;
	queue.push_front(root);
	std::cout << n+1 << '\n';
	while (size) {
		int key = queue.front();
		std::cout << arr[key]->val << " ";
		if (arr[key]->left != -1) {
			queue.push_back(arr[key]->left);
			++size;
			std::cout << ++k << " ";
		}
		else {
			std::cout << 0 << " ";
		}
		if (arr[key]->right != -1) {
			++size;
			queue.push_back(arr[key]->right);
			std::cout << ++k << '\n';
		}
		else {
			std::cout << 0 << '\n';
		}
		--size;
		queue.pop_front();
	}
}

void getDif(Node** arr, int root) {
	if (root != -1) {
		arr[root]->dif = 0;
		if (arr[root]->right != -1) {
			arr[root]->dif = std::max(arr[arr[root]->right]->count_left, arr[arr[root]->right]->count_right) + 1;
		}
		if (arr[root]->left != -1) {
			arr[root]->dif -= std::max(arr[arr[root]->left]->count_left, arr[arr[root]->left]->count_right) + 1;
		}
	}
}

int insert(Node** arr, int val, int root, int n) {
	if ()
}


int main() {
	int n; std::cin >> n;
	int key, left, right;
	Node** arr = new Node* [n + 1];
	Node* nd;
	for (int i = 0; i < n; ++i) {
		std::cin >> key >> left >> right;
		nd = new Node(key, left - 1, right - 1);
		arr[i] = nd;
	}

	for (int i = 0; i < n; ++i) {
		travelSet(arr, i);
	}
	int val; std::cin >> val;
	int root = insert(arr, val, 0, n);
	//for (int i = 0; i < n + 1; ++i) {
	//	std::cout << arr[i]->val << " " << arr[i]->left << " " << arr[i]->right << '\n';
	//}
	PrintBST(arr, n, root);
	return 0;
}