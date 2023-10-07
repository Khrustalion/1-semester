#include <iostream>


void merge(int* arr, int left, int mid, int right) {
	int it1 = 0, it2 = 0;
	int* tmp = new int[right - left];
	while ((left + it1) < mid && (mid + it2) < right) {
		if (arr[left + it1] <= arr[mid + it2]) {
			tmp[it1 + it2] = arr[left + it1];
			++it1;
		}
		else {
			tmp[it1 + it2] = arr[mid + it2];
			++it2;
		}
	}
	while ((left + it1) < mid) {
		tmp[it1 + it2] = arr[left + it1];
		++it1;
	}
	while ((mid + it2) < right) {
		tmp[it1 + it2] = arr[mid + it2];
		++it2;
	}
	for (int i = 0; i < right - left; ++i) {
		arr[left + i] = tmp[i];
	}
}


int merge_sort(int* arr, int left, int right) {
	if (left >= right - 1) {
		return 0;
	}
	int mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid, right);
	merge(arr, left, mid, right);
	return 0;
}


int main() {
	int n; std::cin >> n;
	long long first_edge = 0, res = 0;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	merge_sort(arr, 0, n);
	for (int i = n-1; i > 0; --i) {
		if (i > 0 && arr[i] - 1 <= arr[i - 1]) {
			if (first_edge == 0) {
				first_edge = arr[i - 1];
			}
			else {
				res += first_edge * arr[i - 1];
				first_edge = 0;
			}
			--i;
		}
	}
	std::cout << res;
	delete[] arr;
	return 0;
}