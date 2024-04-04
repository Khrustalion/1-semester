#include <iostream>

void print_avl(int* arr, int l, int r) {
	if (l <= r) {
		int mid = (l + r) / 2;
		std::cout << arr[mid] << " ";
		print_avl(arr, l, mid - 1);
		print_avl(arr, mid + 1, r);
	}
}

int main() {
	int n; std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	print_avl(arr, 0, n - 1);
	return 0;
}