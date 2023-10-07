#include <iostream>


void merge(int** arr, int** tmp, int left, int right, int mid) {
	int it1 = 0, it2 = 0;
	while ((left + it1) < mid && (mid + it2 < right)) {
		if (arr[left + it1][0] <= arr[mid + it2][0]) {
			tmp[left + it1 + it2][0] = arr[left + it1][0];
			tmp[left + it1 + it2][1] = arr[left + it1][1];
			++it1;
		}
		else {
			tmp[left + it1 + it2][0] = arr[mid + it2][0];
			tmp[left + it1 + it2][1] = arr[mid + it2][1];
			++it2;
		}
	}
	while ((left + it1) < mid) {
		tmp[left + it1 + it2][0] = arr[left + it1][0];
		tmp[left + it1 + it2][1] = arr[left + it1][1];
		++it1;
	}
	while ((mid + it2) < right) {
		tmp[left + it1 + it2][0] = arr[mid + it2][0];
		tmp[left + it1 + it2][1] = arr[mid + it2][1];
		++it2;
	}
	for (int i = 0; i < it1 + it2; ++i) {
		arr[left + i][0] = tmp[left + i][0];
		arr[left + i][1] = tmp[left + i][1];
	}
}


void merge_sort(int** arr, int** tmp, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, tmp, left, mid);
		merge_sort(arr, tmp, mid, right);
		merge(arr, tmp, left, right, mid);
	}
}


int main() {
	int n; std::cin >> n;
	int** arr = new int* [n];
	int** tmp = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[2];
		tmp[i] = new int[2];
		std::cin >> arr[i][0];
		arr[i][1] = i;
	}
	merge_sort(arr, tmp, 0, n);
	for (int i = 0; i < n; ++i) {
		arr[i][0] += (arr[i][1] - i);
		arr[i][1] = i;
	}
	bool not_sorted = false;
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i][0] > arr[i + 1][0]) {
			if ((arr[i][0] - arr[i + 1][0]) == 1) {
				std::cout << ":(";
				return 0;
			}
			not_sorted = false;
		}
	}
	if (not_sorted) {
		merge_sort(arr, tmp, 0, n);
	}
	for (int i = 0; i < n; ++i) {
		arr[i][0] += (arr[i][1] - i);
		arr[i][1] = i;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i][0] > arr[i + 1][0]) {
			std::cout << ":(";
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i][0] << " ";
	}
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
		delete[] tmp[i];
	}
	return 0;
}