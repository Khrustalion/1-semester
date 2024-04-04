#include <iostream>


struct ListNode {
	long long val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	long long n, num; std::cin >> n;
	ListNode* head = new ListNode();
	ListNode* tail = head;
	char action;
	for (int _ = 0; _ < n; ++_) {
		std::cin >> action;
		if (action == '-' && head != tail) {
			head = head->next;
			std::cout << head->val << '\n';
		}
		else if (action == '+') {
			std::cin >> num;
			tail->next = new ListNode(num);
			tail = tail->next;
		}
	}
	return 0;
}