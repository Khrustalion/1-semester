#include <iostream>
#include <algorithm>

int binarySearchMen(long long women_i, long long* men, long long n, long long sum) {
	long long i = -1, j = n, mid;
	while (i + 1 < j) {
		mid = (i + j) / 2;
		if (men[mid] + women_i > sum) j = mid;
		else i = mid;
	}
	return i + 1;
}

long long binarySearch(long long sum, long long* women, long long* men, long long n) {
	long long count = 0;
	for (int i = 0; i < n; ++i) {
		if (women[i] + men[n - 1] <= sum) {
			count += n;
		}
		else {
			count += binarySearchMen(women[i], men, n, sum);
		}
	}
	return count;
}


int main() {
	long long n, k; std::cin >> n >> k;
	long long ind = (n + n % k) / k;
	long long* men = new long long[n];

	long long* women = new long long[n];
	long long* tmp = new long long[2 * n];
	for (int i = 0; i < n; ++i) {
		std::cin >> men[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> women[i];
	}
	std::sort(men, men + n);
	std::sort(women, women + n);

	long long i = women[0] + men[0], j = women[n - 1] + men[n - 1] + 1, mid, c;
	while (i + 1 < j) {
		mid = (i + j) / 2;
		if (binarySearch(mid, women, men, n) >= k) j = mid;
		else i = mid;
	}
	std::cout << j;
	return 0;
}