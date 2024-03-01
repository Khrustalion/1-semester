#include <iostream>
#include <vector>
#include <string>

void SiftDown(long long** heap, long long ind, long long heap_size) {
	long long left = 0;
	long long right = 0;
	long long tmp = left;
	while (2 * ind + 1 < heap_size) {
		left = 2 * ind + 1;
		right = left + 1;
		tmp = left;
		if (right < heap_size && (heap[right][1] > heap[left][1] || heap[right][1] == heap[left][1] && heap[right][0] > heap[left][0])) {
			tmp = right;
		}
		if (heap[ind][1] > heap[tmp][1] || heap[ind][1] == heap[tmp][1] && heap[ind][0] > heap[tmp][0]) break;
		std::swap(heap[ind], heap[tmp]);
		ind = tmp;
	}
}

void ExtractMax(long long** heap, long long heap_size) {
	std::swap(heap[0], heap[heap_size - 1]);
	SiftDown(heap, 0, heap_size - 1);
}

void CreateHeap(long long** heap, long long heap_size) {
	for (long long i = heap_size / 2 - 1; i >= 0; --i) {
		SiftDown(heap, i, heap_size);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n, m; std::cin >> n;
	std::vector<long long> cities;
	long long** ratings = new long long*[n];
	long long** moneys = new long long*[n];
	long long ratings_size = n;
	long long moneys_size = n;
	for (long long i = 0; i < n; ++i) {
		ratings[i] = new long long[2];
		moneys[i] = new long long[2];
		long long code, money, rating;
		std::cin >> code >> rating >> money;
		ratings[i][0] = code;
		ratings[i][1] = rating;
		moneys[i][0] = code;
		moneys[i][1] = money;
	}
	CreateHeap(ratings, n);
	CreateHeap(moneys, n);
	std::vector<long long> arr;
	std::string action;
	std::cin >> m;
	while (ratings_size) {
		if (ratings[0][0] == moneys[0][0]) {
			cities.push_back(ratings[0][0]);
			ExtractMax(ratings, ratings_size);
			--ratings_size;
			ExtractMax(moneys, moneys_size);
			--moneys_size;
		}
		else if (arr.size() != m) {
			arr.push_back(ratings[0][0]);
			std::cin >> action;
			if (action == "YES") {
				cities.push_back(ratings[0][0]);
			}
			ExtractMax(ratings, ratings_size);
			--ratings_size;
		}
		else {
			ExtractMax(ratings, ratings_size);
			--ratings_size;
		}
	}
	for (long long i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
	for (long long i = 0; i < cities.size(); ++i) {
		std::cout << cities[i] << " ";
	}
	return 0;
}