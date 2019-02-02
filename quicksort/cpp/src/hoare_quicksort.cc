#include <vector>

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(std::vector<int>& arr, int low, int high, int pivot){
	int i = low - 1;
	int j = high + 1;

	while(true){
		do{
			++i;
		}while(arr[i] < pivot);

		do{
			--j;
		}while(arr[j] > pivot);

		if(i >= j){
			return j;
		}
		swap(&arr[i], &arr[j]);
	}
}

void quicksort(std::vector<int>& unsorted_elements, int low, int high){
	if(low < high){
	    int pivot = unsorted_elements[(low + high) / 2];
		int partitioning_index = partition(unsorted_elements, low, high, pivot);
		quicksort(unsorted_elements, low, partitioning_index);
		quicksort(unsorted_elements, partitioning_index+1, high);
	}
}

void hoareQuicksort(std::vector<int>& unsorted_elements) {
	quicksort(unsorted_elements, 0, unsorted_elements.size() - 1);
}
