#include <iostream>


struct Node {
	int val;
	int pos;
	Node* next;
	Node* prevue;
	Node() : val(0), pos(0), prevue(nullptr), next(nullptr){}
	Node(int val) : val(val), pos(1), prevue(nullptr), next(nullptr) {}
	Node(int val, int pos, Node* prevue, Node* next) : val(val), pos(pos), prevue(prevue), next(next) {}
};

struct List {
	Node* head = new Node();
	Node* tail = head;
	void push_back(int val, int pos) {
		tail->val = val;
		tail->pos = pos;
		tail->next = new Node(0, 0, tail, nullptr);
		tail = tail->next;
	}

	int pop(Node* node_now) {
		Node* node_tmp;
		if (node_now->prevue == nullptr) {
			node_tmp = node_now;
			node_now = node_now->next;
			node_now->prevue = nullptr;
			return node_tmp->val;
		}
		else if (node_now->next == nullptr) {
			node_tmp = node_now;
			node_now = node_now->prevue;
			node_now->next = nullptr;
			return node_tmp->val;
		}
		else {
			node_tmp = node_now;
			node_now = node_now->next;
			node_now->prevue = node_tmp->prevue;
			node_tmp->prevue->next = node_now;
			return node_tmp->val;
		}
		delete[] node_tmp;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, tmp; std::cin >> n;
	List days;
	int* answer = new int[n] {0};
	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		days.push_back(tmp, i);
	}
	Node* pointer = (days.head)->next;
	Node* tmp_p;
	while (pointer != days.tail) {
		tmp_p = pointer->prevue;
		while (tmp_p != nullptr) {
			if (pointer->val > tmp_p->val) {
				answer[tmp_p->pos] = pointer->pos - tmp_p->pos;
				days.pop(tmp_p);
				tmp_p = tmp_p->prevue;
			}
			else break;
			
		}
		pointer = pointer->next;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << ((answer[i] != 0) ? answer[i] : -1) << " ";
	}
	delete[] pointer, tmp_p, answer, days;
	return 0;
}