#include <iostream>


void QuickSort(long long* arr, int left, int right) {
	long long mid = (arr[left] + arr[right]) / 2;
	int i = left, j = right;
	while (i <= j) {
		while (arr[i] < mid) {
			++i;
		}
		while (arr[j] > mid) {
			--j;
		}
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}

	if (left < j) {
		QuickSort(arr, left, j);
	}
	if (right > i) {
		QuickSort(arr, i, right);
	}
}


int main() {
	int n; std::cin >> n;
	long long* arr = new long long[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	QuickSort(arr, 0, n-1);
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
}