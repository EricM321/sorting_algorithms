#include <vector>

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(std::vector<int>& arr, int low, int high, int pivot){
	for(int j = low; j <= high - 1; ++j){
		if(arr[j] < pivot){
			swap(&arr[low], &arr[j]);
			++low;
		}
	}
	swap(&arr[low], &arr[high]);
	return low;
}

void quicksort(std::vector<int>& unsorted_elements, int low, int high){
	if(low < high){
	    int pivot = unsorted_elements[high];
		int partitioning_index = partition(unsorted_elements, low, high, pivot);
		quicksort(unsorted_elements, low, partitioning_index - 1);
		quicksort(unsorted_elements, partitioning_index + 1, high);
	}
}

void quicksort(std::vector<int>& unsorted_elements) {
	quicksort(unsorted_elements, 0, unsorted_elements.size()-1);
}
