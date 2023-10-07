#include <iostream>


void QuickSort(int** arr, int left, int right) {
	int i = left, j = right, pivot = (arr[left][0] + arr[right][0]) / 2;
	while (i <= j) {
		while (arr[i][0] < pivot) ++i;
		while (arr[j][0] > pivot) --j;
		if (i <= j) {
			int* tmp = new int[2];
			tmp[0] = arr[i][0];
			tmp[1] = arr[i][1];
			arr[i][0] = arr[j][0];
			arr[i][1] = arr[j][1];
			arr[j][0] = tmp[0];
			arr[j][1] = tmp[1];
			++i;
			--j;
			delete[] tmp;
		}
	}
	if (left < j) QuickSort(arr, left, j);
	if (i < right) QuickSort(arr, i, right);
}
	

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n; std::cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[2];
		std::cin >> arr[i][0] >> arr[i][1];
	}
	QuickSort(arr, 0, n-1);
	long long res_day = 0, answer = 0;
	for (int i = 0; i < n; ++i) {
		res_day += arr[i][0];
		answer += (arr[i][1] - res_day);
	}
	std::cout << answer;

	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
	}
	return 0;
}