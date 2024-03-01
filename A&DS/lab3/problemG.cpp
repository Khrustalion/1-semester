#include <iostream>
#include <algorithm>


struct Node {
	int val;
	Node* next;

	Node() : val(0), next(nullptr) {}
	Node(int val) : val(val), next(nullptr) {}
	Node(int val, Node* next) : val(val), next(next) {}
};


struct ListNode {
	Node* head = new Node;
	Node* tail = head;

	void push(int x) {
		tail->next = new Node(x, nullptr);
		tail = tail->next;
	}
};


bool f(Node* current, int max_dist, int k) {
	int cnt_b = 1;
	int last_val = current->val;
	current = current->next;
	while (current != nullptr) {
		if (current->val - last_val >= max_dist) {
			++cnt_b;
			last_val = current->val;
		}
		current = current->next;
	}
	return cnt_b < k;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k, c; std::cin >> n >> k;
	int* arr = new int[n];
	ListNode bench;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	std::sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		bench.push(arr[i]);
	}
	delete[] arr;
	int i = 1;
	int j = bench.tail->val + 1;
	int mid = (i + j) / 2;

	while (i + 1 < j) {
		mid = (i + j) / 2;
		if (f(bench.head->next, mid, k)) j = mid;
		else i = mid;
		
	}
	std::cout << i;
	return 0;
}