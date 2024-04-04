#include <iostream>

void SiftUp(int* heap, int i, int n) {
	while (heap[i] > heap[(i - 1) / 2]) {
		std::swap(heap[i], heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void SiftDown(int* heap, int i, int heap_size) {
	int left = 0;
	int right = 0;
	int tmp = left;
	while (2 * i + 1 < heap_size) {
		left = 2 * i + 1;
		right = 2 * i + 2;
		tmp = left;
		if (right < heap_size && heap[right] > heap[tmp]) {
			tmp = right;
		}
		if (heap[i] >= heap[tmp]) {
			break;
		}
		std::swap(heap[i], heap[tmp]);
		i = tmp;
	}
}

int ExtructMax(int* heap, int heap_size) {
	std::swap(heap[0], heap[heap_size - 1]);
	--heap_size;
	SiftDown(heap, 0, heap_size);
	return heap_size;
}

int main() {
	int n; std::cin >> n;
	int heap_size = n;
	int* heap = new int[heap_size];
	for (int i = 0; i < heap_size; ++i) {
		std::cin >> heap[i];
	}
	for (int i = heap_size / 2 - 1; i >= 0; --i) {
		SiftDown(heap, i, heap_size);
	}
	while (heap_size != 1) {
		heap_size = ExtructMax(heap, heap_size);
	}
	for (int i = 0; i < n; ++i) {
		std::cout << heap[i] << " ";
	}
	return 0;
}