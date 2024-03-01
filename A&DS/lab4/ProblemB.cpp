#include <iostream>
#include <algorithm>

struct heap {
	long long* heap;
	long long max_heap_size;
	long long heap_size;
};

void SiftDown(long long* heap, long long i, long long heap_size) {
	long long left_child = 0;
	long long right_child = 0;
	long long tmp;
	while ((i * 2 + 1) < heap_size) {
		left_child = 2 * i + 1;
		right_child = 2 * i + 2;
		tmp = left_child;
		if ((right_child < heap_size) && (heap[left_child] > heap[right_child])) {
			tmp = right_child;
		}
		if (heap[i] <= heap[tmp]) {
			break;
		}
		std::swap(heap[i], heap[tmp]);
		i = tmp;
	}
}

void CreateHeap(long long* heap, long long heap_size) {
	for (long long i = heap_size / 2 - 1; i >= 0; --i) {
		SiftDown(heap, i, heap_size);
	}
}

void SiftUp(long long* heap, long long i) {
	while (heap[i] < heap[(i - 1) / 2]) {
		std::swap(heap[i], heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long heaps_size = 4;
	long long count_heaps = -1;
	heap** heaps = new heap*[heaps_size];

	std::string action;
	while (std::cin >> action) {
		if (action == "create") {
			heaps[++count_heaps] = new heap;
			heaps[count_heaps]->max_heap_size = 2;
			heaps[count_heaps]->heap_size = 0;
			heaps[count_heaps]->heap = new long long[heaps[count_heaps]->max_heap_size];

			if (count_heaps == heaps_size - 1) {
				long long heaps_size_new = heaps_size * 2;
				heap** tmp_heaps = new heap * [heaps_size_new];
				for (long long i = 0; i < heaps_size; ++i) {
					tmp_heaps[i] = heaps[i];
				}
				heaps_size = heaps_size_new;
				heaps = tmp_heaps;
			}
		}
		else if (action == "insert") {
			long long k, x; std::cin >> k >> x;
			heaps[k]->heap[heaps[k]->heap_size] = x;
			SiftUp(heaps[k]->heap, heaps[k]->heap_size);
			++heaps[k]->heap_size;

			if (heaps[k]->heap_size == heaps[k]->max_heap_size) {
				heap* new_heap = new heap;
				new_heap->max_heap_size = heaps[k]->heap_size * 2;
				new_heap->heap_size = heaps[k]->heap_size;
				new_heap->heap = new long long[new_heap->max_heap_size];
				for (int i = 0; i < heaps[k]->heap_size; ++i) {
					new_heap->heap[i] = heaps[k]->heap[i];
				}
				delete[] heaps[k]->heap;

				heaps[k] = new_heap;
			}
		}
		else if (action == "extract-min") {
			long long k; std::cin >> k;
			if (heaps[k]->heap_size > 0) {
				std::cout << heaps[k]->heap[0] << '\n';
				std::swap(heaps[k]->heap[0], heaps[k]->heap[--heaps[k]->heap_size]);
				SiftDown(heaps[k]->heap, 0, heaps[k]->heap_size);
			}
			else {
				std::cout << "*" << '\n';
			}
		}
		else if (action == "decrease-key") {
			long long k, x, y, ind;
			std::cin >> k >> x >> y;
			for (int i = 0; i < heaps[k]->heap_size; ++i) {
				if (heaps[k]->heap[i] == x) {
					heaps[k]->heap[i] = y;
					SiftUp(heaps[k]->heap, i);
					break;
				}
			}
		}
		else if (action == "merge") {
			long long k, m; std::cin >> k >> m;
			heap* new_heap = new heap;
			new_heap->heap_size = (heaps[k]->heap_size + heaps[m]->heap_size);
			new_heap->max_heap_size = std::max((long long)100, (heaps[k]->heap_size + heaps[m]->heap_size) * 2);
			new_heap->heap = new long long[new_heap->max_heap_size];
			long long ind = -1;
			for (long long i = 0; i < heaps[k]->heap_size; ++i) {
				new_heap->heap[++ind] = heaps[k]->heap[i];
			}
			for (long long i = 0; i < heaps[m]->heap_size; ++i) {
				new_heap->heap[++ind] = heaps[m]->heap[i];
			}
			heaps[++count_heaps] = new_heap;
			CreateHeap(heaps[count_heaps]->heap, heaps[count_heaps]->heap_size);
			if (count_heaps == heaps_size - 1) {
				long long heaps_size_new = heaps_size * 2;
				heap** tmp_heaps = new heap * [heaps_size_new];
				for (long long i = 0; i < heaps_size; ++i) {
					tmp_heaps[i] = heaps[i];
				}

				heaps_size = heaps_size_new;
				heaps = tmp_heaps;
			}
		}
	}

	for (long long i = 0; i < count_heaps; ++i) {
		delete[] heaps[i]->heap;
		delete[] heaps[i];
	}
	return 0;
}