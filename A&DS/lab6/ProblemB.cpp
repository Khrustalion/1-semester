#include <iostream>
#include <vector>
#include <list>

struct Node {
	int val;
	int count_right = -1;
	int count_left = -1;
	int right;
	int left;
	int dif;

	Node(int val, int left, int right) : val{ val }, left { left }, right{ right } {}
};

int travelset(Node** arr, int ind) {
	//std::cout << arr[ind]->val << " " << arr[ind]->left << " " << arr[ind]->right << " " << arr[ind]->count_left << " " << arr[ind]->count_right << '\n';
	if (arr[ind]->count_right == -1) {
		if (arr[ind]->right != 0) {
			arr[ind]->count_right = travelset(arr, arr[ind]->right - 1);
		}
	}
	if (arr[ind]->count_left == -1) {
		if (arr[ind]->left != 0) {
			arr[ind]->count_left = travelset(arr, arr[ind]->left - 1);
		}
	}
	arr[ind]->dif = arr[ind]->count_right - arr[ind]->count_left;
	return std::max(arr[ind]->count_left, arr[ind]->count_right) + 1;
}

int SmallLeftTurn(Node** arr, int root) {
	int right_child = arr[root]->right - 1;
	int tmp = arr[right_child]->left - 1;
	arr[right_child]->left = root + 1;
	arr[root]->right = tmp + 1;
	return right_child;
}

int BigLeftTurn(Node** arr, int root) {
	int right_child = arr[root]->right - 1;
	int right_left_child = arr[right_child]->left - 1;
	int left = arr[right_left_child]->left - 1;
	int right = arr[right_left_child]->right - 1;
	arr[right_left_child]->right = right_child + 1;
	arr[right_left_child]->left = root + 1;
	arr[root]->right = left + 1;
	arr[right_child]->left = right + 1;
	return right_left_child;
}


int main() {
	int n; std::cin >> n;
	int key, left, right;
	Node** arr = new Node * [n];
	Node* nd;
	for (int i = 0; i < n; ++i) {
		std::cin >> key >> left >> right;
		nd = new Node(key, left, right);
		arr[i] = nd;
	}

	for (int i = 0; i < n; ++i) {
		travelset(arr, i);
	}
	Node* root = nullptr;
	int root_i;
	for (int i = 0; i < n; ++i) {
		if (arr[i]->dif == 2) {
			root = arr[i];
			root_i = i;
			break;
		}
	}
	/*for (int i = 0; i < n; ++i) {
		std::cout << arr[i]->val << " " << arr[i]->dif << '\n';
	}*/
	int new_root;
	if (arr[root->right - 1]->dif == -1) {
		new_root = BigLeftTurn(arr, root_i);
	}
	else {
		new_root = SmallLeftTurn(arr, root_i);
	}

	std::list<int> queue;
	int size = 1;
	int k = 1;
	queue.push_front(new_root);
	std::cout << n << '\n';
	while (size) {
		int key = queue.front();
		std::cout << arr[key]->val << " ";
		if (arr[key]->left != 0) {
			queue.push_back(arr[key]->left - 1);
			++size;
			std::cout << ++k << " ";
		}
		else {
			std::cout << 0 << " ";
		}
		if (arr[key]->right != 0) {
			++size;
			queue.push_back(arr[key]->right - 1);
			std::cout << ++k << '\n';
		}
		else {
			std::cout << 0 << '\n';
		}
		--size;
		queue.pop_front();
	}

	return 0;
}