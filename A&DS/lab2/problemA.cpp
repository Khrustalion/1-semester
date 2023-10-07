#include <iostream>


void sort_insertion(int* arr,  int len_arr) {
	for (int i = 1; i < len_arr; ++i) {
		int j = i - 1, temp = arr[i];
		while (j >= 0 && arr[j] > temp) {
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = temp;
	}
}


int main(int argc, char** argv) {
	int n; std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	sort_insertion(arr, n);
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	delete[] arr;
}