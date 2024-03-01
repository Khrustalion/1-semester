#include <iostream>



struct Node {
	int val;
	Node* next;
	Node* prevue;
	Node() : val(0), next(nullptr), prevue(nullptr) {}
	Node(int val) : val(val), next(nullptr), prevue(nullptr) {}
	Node(int val, Node* next, Node* prevue) : val(val), next(next), prevue(prevue) {}
};


struct List {
	Node* left = new Node;
	Node* right = left;
	int size = 0;
	void push_back(int val) {
		right->val = val;
		right->next = new Node(0, nullptr, right);
		right = right->next;
		++size;
	}

	int pop_start() {
		left = left->next;
		--size;
		return left->prevue->val;
	}

	int pop_back() {
		right = right->prevue;
		--size;
		return right->val;
	}
};


int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int min(int a, int b, int c) {
	return min(a, min(b, c));
}

int second_max(int a, int b, int c) {
	return a + b + c - max(a, b, c) - min(a, b, c);
}



int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m, val, val_start, val_back; std::cin >> n >> m;
	List backpack;
	for (int _ = 0; _ < n; ++_) {
		std::cin >> val;
		if (backpack.size < m) {
			backpack.push_back(val);
		}
		else {
			val_start = backpack.pop_start();
			val_back = backpack.pop_back();
			backpack.push_back(second_max(val, val_start, val_back));
			backpack.push_back(max(val, val_start, val_back));
		}
	}
	while (backpack.size > 0) {
		std::cout << backpack.pop_start() << " ";
	}
	return 0;
}