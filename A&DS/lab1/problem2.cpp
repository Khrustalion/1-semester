#include <iostream>
//#include <stdlib.h>

int main() {
	int n, k;
	std::cin >> n >> k;
	k = k > 0 ? k : (n - abs(k) % n) % n;
	int *nums = new int [n];
	for (int i = 0; i < n; ++i) {
		std::cin >> nums[(i + k) % n];
	}
	for (int i = 0; i < n; ++i) {
		std::cout << nums[i] << " ";
	}
	return 0;
}