#include <iostream>
#include <string>

struct Node {
	int coef;
	char element;
	Node* next;

	Node() : coef(0), element(' '), next(nullptr) {}
	Node(int coef, char element, Node* next) : coef(coef), element(element), next(next) {}
};

struct Stack {
	Node* head = nullptr;
	Node* tail = head;

	void push(int x, char element) {
		head = new Node(x, element, head);
	}
};

int main() {
	std::string str; std::cin >> str;
	int* alph = new int[26] {0};
	char element;
	if (isalpha(str[0])) element = str[0];
	int n = (str).size(), number = 0;
	std::cout << n << '\n';
	Stack stack;

	for (int i = 0; i < n; ++i) {
		if (i > 0) alph[element - 1] = number;
		if (isdigit(str[i])) {
			number = number * 10 + (str[i] - '0');
		}
		else if (str[i] == '(') {
			while (str[i] != ')') ++i;
			i += 2;
		}
		if (isalpha(str[i])) {
			element = str[i];
			number = 0;
		}
	}
	for (int i = 0; i < 26; ++i) {
		std::cout << 'A' + i << " " << alph[i] << '\n';
	}
	return 0;
}