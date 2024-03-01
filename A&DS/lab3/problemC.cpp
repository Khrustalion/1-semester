#include <iostream>
#include <string>


void CountSort(std::string* messages, int pos, int n) {
	char min = 127, max = -128;
	
	for (int i = 0; i < n; ++i) {
		if (messages[i][pos] < min) min = messages[i][pos];
		if (messages[i][pos] > max) max = messages[i][pos];
	}
	int* tmp = new int[max - min + 1] {0};
	for (int i = 0; i < n; ++i) {
		tmp[messages[i][pos] - min] += 1;
	}
	for (int i = 1; i < max - min + 1; ++i) {
		tmp[i] += tmp[i - 1];
	}
	std::string *answer = new std::string [n];
	for (int i = n - 1; i >= 0; --i) {
		answer[(tmp[messages[i][pos] - min]--) - 1] = messages[i];
	}
	for (int i = 0; i < n; ++i) {
		messages[i] = answer[i];
	}
	delete[] answer;
}


int main() {
	int n, k, t;
	std::cin >> n >> k >> t;
	if (t > k){
		t = k;
	}
	std::string* messages = new std::string [n];
	for (int i = 0; i < n; ++i) {
		std::cin >> messages[i];
	}
	for (int i = 0; i < t; ++i) {
		CountSort(messages, k - i - 1, n);
	}
	for (int i = 0; i < n; ++i) {
		std::cout << messages[i] << '\n';
	}
	return 0;
}