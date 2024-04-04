#include <iostream>
#include <vector>

struct pair {
	long long money = 0;
	long long time = 0;
};

void SiftDown(std::vector<pair>& heap, long long heap_size, long long ind) {
	long long left = 0;
	long long right = 0;
	long long tmp = left;
	while (2 * ind + 1 < heap_size) {
		left = 2 * ind + 1;
		right = 2 * ind + 2;
		tmp = left;
		if (right < heap_size && heap[right].money < heap[left].money) {
			tmp = right;
		}
		
		if (heap[ind].money <= heap[tmp].money) break;

		std::swap(heap[ind], heap[tmp]);
		ind = tmp;
	}
}

void SiftDownTime(std::vector<pair>& heap, long long heap_size, long long ind) {
	long long left = 0;
	long long right = 0;
	long long tmp = left;
	while (2 * ind + 1 < heap_size) {
		left = 2 * ind + 1;
		right = 2 * ind + 2;
		tmp = left;
		if (right < heap_size && heap[right].time < heap[left].time) {
			tmp = right;
		}

		if (heap[ind].time <= heap[tmp].time) break;

		std::swap(heap[ind], heap[tmp]);
		ind = tmp;
	}
}

void ExtractMinTime(std::vector<pair>& heap, long long heap_size) {
	std::swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	SiftDownTime(heap, heap.size(), 0);
}

void SiftUp(std::vector<pair>& heap, long long ind) {
	while (ind > 0 && heap[(ind - 1) / 2].time > heap[ind].time) {
		std::swap(heap[(ind - 1) / 2], heap[ind]);
		ind = (ind - 1) / 2;
	}
}

void SiftUpMoney(std::vector<pair>& heap, long long ind) {
	while (ind > 0 && heap[(ind - 1) / 2].money > heap[ind].money) {
		std::swap(heap[(ind - 1) / 2], heap[ind]);
		ind = (ind - 1) / 2;
	}
}

void CreateHeap(std::vector<pair>& heap, long long heap_size) {
	for (int i = heap_size / 2 - 1; i >= 0; --i) {
		SiftDown(heap, heap_size, i);
	}
}

void ExtractMin(std::vector<pair>& heap, long long heap_size) {
	std::swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	SiftDown(heap, heap.size(), 0);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n, m;
	long long sum = 0;
	std::cin >> n >> m;
	std::vector<pair> workers;
	std::vector<pair> work;
	long long num;
	pair shaurm;
	for (int i = 0; i < n; ++i) {
		std::cin >> shaurm.money;
		shaurm.time = 0;
		workers.push_back(shaurm);
	}
	CreateHeap(workers, workers.size());
	long long t, f;

	for (int i = 0; i < m; ++i) {
		std::cin >> t >> f;
		while (work.size() > 0 && work[0].time <= t) {
			shaurm.money = work[0].money;
			shaurm.time = work[0].time;
			ExtractMinTime(work, work.size());
			workers.push_back(shaurm);
			SiftUpMoney(workers, workers.size() - 1);
		}
		if (workers.size() > 0) {
			shaurm.money = workers[0].money;
			shaurm.time = t + f;
			sum += shaurm.money * f;
			ExtractMin(workers, workers.size());
			work.push_back(shaurm);
			SiftUp(work, work.size() - 1);
			//std::cout << "---------" << '\n';
			//for (int i = 0; i < work.size(); ++i) {
			//	std::cout << work[i].money << " " << work[i].time << '\n';
			//}
		}
	}
	
	std::cout << sum;
	return 0;
}