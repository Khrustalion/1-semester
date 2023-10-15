#include <iostream>
#include <cstdint>


void QuickSort(int* arr, int left, int right, const int k, const int n) {
	int i = left, j = right;
	int32_t pivot = arr[(i + j) / 2];
	while (i <= j) {
		while (arr[i] < pivot) ++i;
		while (pivot < arr[j]) --j;
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}
	if (i < n - k) {
		if (right > i) QuickSort(arr, i, right, k, n);
	}
	else if (i > n - k) {
		if (j > left) QuickSort(arr, left, j, k, n);
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k; std::cin >> n >> k;
	int A, B, C;
	std::cin >> A >> B >> C;
	int32_t* arr = new int32_t[n];
	std::cin >> arr[0];
	std::cin >> arr[1];
	for (int i = 2; i < n; ++i) {
		arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
	}
	QuickSort(arr, 0, n - 1, k, n);
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
	int32_t answer = arr[n - 1];
	for (int i = n - 2; i >= n - k; --i) {
		answer ^= arr[i];
	}
	std::cout << answer;
	delete[] arr;
}