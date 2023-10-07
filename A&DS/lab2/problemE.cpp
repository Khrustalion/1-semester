#include <iostream>

void merge(int* arr, int left, int right, unsigned long long& answer) {
	int* tmp = new int[right - left];
	int it1 = 0, it2 = 0, mid = (left + right) / 2;
	while ((left + it1 < mid) && (mid + it2 < right)) {
		if (arr[left + it1] <= arr[mid + it2]) {
			tmp[it1 + it2] = arr[left + it1];
			++it1;
		}
		else {
			answer += mid - left - it1;
			tmp[it1 + it2] = arr[mid + it2];
			++it2;
		}
	}
	while (left + it1 < mid) {
		tmp[it1 + it2] = arr[left + it1];
		++it1;
	}
	while (mid + it2 < right) {
		tmp[it1 + it2] = arr[mid + it2];
		++it2;
	}
	for (int i = 0; i < it1 + it2; ++i) {
		arr[left + i] = tmp[i];
	}


	delete[] tmp;
}


void merge_sort(int* arr, int left, int right, unsigned long long& answer) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid, answer);
		merge_sort(arr, mid, right, answer);
		merge(arr, left, right, answer);
	}
}



int main() {
	int cnt = 0, n; std::cin >> n;
	unsigned long long answer = 0;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	merge_sort(arr, 0, n, answer);


	std::cout << answer;
	return 0;
}