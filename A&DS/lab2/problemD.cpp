#include <iostream>


int main() {
	int n; std::cin >> n;
	int cnt = n;
	int* arr = new int[n] {1};
	for (int i = 1; i < n; ++i) {
		arr[i] = i + 1;
	}
	for (int i = 2; i < n; ++i) {
		int tmp = arr[i / 2];
		arr[i / 2] = arr[i];
		arr[i] = tmp;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}