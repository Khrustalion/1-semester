#include <iostream>

struct Node {
	int val;
	Node* next;

	Node() : val(0), next(nullptr) {}
	Node(int val, Node* next) : val(val), next(next) {}
};

int main() {
	int n, number, i = 0; std::cin >> n;
	Node** arr = new Node*[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new Node(i, nullptr);
	}
	while (std::cin >> number) {
		arr[i]->next = arr[number - 1];
		++i;
	}

	Node* head = arr[0];
	Node* quick = head;
	Node* slow = head;
	while (quick != nullptr && quick->next != nullptr && quick->next->next != nullptr) {
		quick = quick->next->next;
		slow = slow->next;
		if (quick == slow) break;
	}
	if (quick == nullptr || quick->next == nullptr || quick->next->next == nullptr) {
		std::cout << -1;
		return 0;
	}
	int cnt = 0;
	while (head != slow) {
		head = head->next;
		slow = slow->next;
		++cnt;
	}
	std::cout << n - cnt;
	return 0;
}