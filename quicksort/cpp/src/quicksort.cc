#include <vector>
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(std::vector<int> arr, int low, int high){
	int pivot = arr[high];
	int i = (low - 1);
	
	for(int j = low; j <= high - 1; ++j){
		if(arr[j] <= pivot){
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quicksort(std::vector<int> unsorted_elements, int low, int high){
	if(low < high){
		int partitioning_index = partition(unsorted_elements, low, high);
		quicksort(unsorted_elements, low, partitioning_index - 1);
		quicksort(unsorted_elements, partitioning_index + 1, high);
	}
}

void quicksort(std::vector<int> unsorted_elements) {
	quicksort(unsorted_elements, 0, unsorted_elements.size());
}
