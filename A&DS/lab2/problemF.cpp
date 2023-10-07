#include <iostream>


void merge(long long** arr, int left, int right, int mid) {
	int it1 = 0, it2 = 0;
	long long** tmp = new long long*[right - left];
	for (int i = 0; i < right - left; ++i) {
		tmp[i] = new long long[2];
	}
	while ((left + it1) < mid && (mid + it2 < right)) {
		if (arr[left + it1][0] < arr[mid + it2][0]) {
			tmp[it1 + it2][0] = arr[left + it1][0];
			tmp[it1 + it2][1] = arr[left + it1][1];
			++it1;
		}
		else {
			tmp[it1 + it2][0] = arr[mid + it2][0];
			tmp[it1 + it2][1] = arr[mid + it2][1];
			++it2;
		}
	}
	while ((left + it1) < mid) {
		tmp[it1 + it2][0] = arr[left + it1][0];
		tmp[it1 + it2][1] = arr[left + it1][1];
		++it1;
	}
	while ((mid + it2) < right) {
		tmp[it1 + it2][0] = arr[mid + it2][0];
		tmp[it1 + it2][1] = arr[mid + it2][1];
		++it2;
	}
	for (int i = 0; i < it1 + it2; ++i) {
		arr[left + i][0] = tmp[i][0];
		arr[left + i][1] = tmp[i][1];
	}
}


void merge_sort(long long** arr, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid, right);
		merge(arr, left, right, mid);
	}
}


int main() {
	int n, m, k, module = int(pow(10, 9)) + 7;
	std::cin >> n >> m >> k;
	long long* coef = new long long[n];
	long long** grades = new long long* [m];
	for (int i = 0; i < m; ++i) {
		grades[i] = new long long[2];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> coef[i];
	}
	for (int i = 0; i < m; ++i) {
		unsigned long long res = 0;
		for (int j = 0; j < n; ++j) {
			long long grade; std::cin >> grade;
			res = (res + (grade * coef[j])) % module;
		}
		grades[i][0] = res;
		grades[i][1] = i + 1;
	}
	merge_sort(grades, 0, m);
	for (int i = m-1; i >= m - k; --i) {
		std::cout << grades[i][1] << " "; //<< grades[i][1] << "\n";
	}
	return 0;
}