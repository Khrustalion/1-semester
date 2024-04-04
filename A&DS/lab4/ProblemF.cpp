#include <iostream>
#include <vector>
#include <algorithm>


struct pair {
	int num;
	int pow;
};

void SiftDown(std::vector<pair>& heap) {
	int ind = 0;
	int left = 0;
	int right = 0;
	int tmp = left;
	int n = heap.size();
	while (2 * ind + 1 < n) {
		left = 2 * ind + 1;
		right = 2 * ind + 2;
		tmp = left;
		if (right < n && std::pow(heap[right].num, heap[right].pow) < std::pow(heap[left].num, heap[left].pow)) {
			tmp = right;
		}

		if (std::pow(heap[ind].num, heap[ind].pow) <= std::pow(heap[tmp].num, heap[tmp].pow)) break;

		std::swap(heap[ind], heap[tmp]);

		ind = tmp;
	}
}

int main() {
	int n; std::cin >> n;
	int m = 100000000;
	int* numbers = new int[m] {0};
	std::vector<pair> prime_num;

	for (int i = 2; i < m; ++i) {
		if (!numbers[i]) {
			prime_num.push_back({ i, 1 });
		}
		for (int j = i * i; j < m; j += i) {
			numbers[j] = 1;
		}
	}

	delete[] numbers;

	std::vector<int> res;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < prime_num[0].pow; ++j) {
			res.push_back(prime_num[0].num);
		}
		prime_num[0].pow *= 2;
		SiftDown(prime_num);
	}

	std::sort(res.begin(), res.end());
	std::cout << res.size() << '\n';
	for (int i = 0; i < res.size(); ++i) {
		std::cout << res[i] << " ";
	}
	return 0;
}