#include <iostream>

int main() {
	int n; std::cin >> n;
	int* heap = new int[n+1];
	for (int i = 1; i < n; ++i) {
		std::cin >> heap[i];
	}
	for (int i = 1; i < n / 2; ++i) {
		if (2 * i <= n && heap[i] > heap[2*i] || 2*i + 1 <= n && heap[i] > heap[2*i + 1]) {
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES";
	return 0;
}