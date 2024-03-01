#include <iostream>
#include <algorithm>


struct Node {
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int val) : val(val),  next(nullptr) {}
	Node(int val, Node* next) : val(val), next(next) {}


};


struct Stack {
	Node* head = nullptr;
	int size = 0;
	void push(int x) {
		head = new Node(x, head);
		++size;
	}

	int pop() {
		Node* tmp = head;
		int res = tmp->val;
		head = head->next;
		--size;

		delete[] tmp;
		return res;
	}

	int peek() {
		return head->val;
	}
};


int main() {
	int n, tmp; std::cin >> n;
	long long answer = 0;
	long long** arr = new long long*[n];
	Stack stack;
	for (int i = 0; i < n; ++i) {
		arr[i] = new long long[2];
		std::cin >> arr[i][0];
		arr[i][1] = 0;
	}
	for (int i = 0; i < n; ++i) {
		while (stack.size && arr[i][0] < arr[stack.peek()][0]) {
			tmp = stack.pop();
			arr[tmp][1] = i - tmp;
		}
		stack.push(i);
	}
	if (stack.size) tmp = stack.peek();
	while (stack.size) {
		int tmp_1 = stack.pop();
		arr[tmp_1][1] = tmp - tmp_1 + 1;
	}

	for (int i = n - 1; i >= 0; --i) {
		while (stack.size && arr[i][0] < arr[stack.peek()][0]) {
			tmp = stack.pop();
			answer = std::max(answer, arr[tmp][0] * (arr[tmp][1] + tmp - i - 1));
		}
		stack.push(i);
	}
	if (stack.size) tmp = stack.peek();
	while (stack.size) {
		int tmp_l = stack.pop();
		answer = std::max(answer, arr[tmp_l][0] * (arr[tmp_l][1] - tmp + tmp_l));
	}
	std::cout << answer;
	return 0;
}