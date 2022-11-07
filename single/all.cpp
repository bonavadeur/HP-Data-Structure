#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<sys/time.h>
#include<stdlib.h>

using namespace std;


// ham nay bat buoc
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
//

// đoạn này tuỳ thuật toán
void swap(int &xp, int &yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}

void swap2(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void selection_sort(int arr[], int n) {
    int i, j, minIdx;
    for (int i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}


void insertion_sort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;
       while (j >= 0 && arr[j] > key) {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}


void merge(int array[], int const left, int const mid, int const right) {
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];
	auto indexOfSubArrayOne = 0, // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
		indexOfSubArrayTwo = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	int indexOfMergedArray = left; // Khởi tạo chỉ số bắt đầu của mảng lưu kết quả

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}
void mergeSort(int array[], int const begin, int const end) {
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}
void merge_sort(int a[], int n) {
    mergeSort(a, 0, n-1);
}


void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}


void quickSort(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low-1, j = high;
	if (high <= low) return;

	while (1)
	{
		while (arr[++i] < pivot) ;
		while (pivot < arr[--j]) if (j == low) break;
		if (i >= j) break;
		swap2(&arr[i], &arr[j]);
	}
	swap2(&arr[i], &arr[high]);
	quickSort(arr, low, i - 1);
	quickSort(arr, i + 1, high);
}
void quick_sort(int arr[], int n) {
    quickSort(arr, 0, n-1);
}


void quickSort3(int a[], int low, int high) {
	int i = low -1, j = high, p = low - 1, q = high;
	int pivot = a[high];
	if (low >= high)
		return;
	while (1)
	{
		while (a[++i] < pivot) ;
		while (pivot < a[--j]) if (j == low) break;
		if (i >= j) break;
		swap2(&a[i], &a[j]);
		if (a[i] == pivot) swap2(&a[p++], &a[i]);
		if (a[j] == pivot) swap2(&a[j], &a[q--]);
	}

	swap2(&a[i], &a[high]);
	j = i-1; i++;
	for(int k = low; k < p; k++, j--) swap2(&a[k], &a[j]);
	for(int k = high - 1; k > q; k--, i++) swap2(&a[i], &a[k]);

	// Recur two halves
	quickSort3(a, low, j);
	quickSort3(a, i, high);
}
void quick_sort_3(int arr[], int n) {
    quickSort3(arr, 0, n-1);
}


void bubbleSort(int arr[], int n) {
   int i, j; 
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap2(&arr[j], &arr[j+1]); 
}


void shell_sort(int arr[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}


int main() {
    system("cls");

    // bắt buộc
    struct timeval tp;
    int runtime = 0;
    long int start, end;
    
    for(int loop = 0; loop < 10; loop++) {
        // đoạn này sinh n phần tử ngẫu nhiên trong khoảng 0->10n
        // thống nhất test n = 100000
        // int n = 100000;
        // int *arr = (int*) malloc(n*sizeof(int));
        // for(int i = 0; i < n; i++) {
        //     arr[i] = random(1, n * 10);
        // }
        //

        // nearly sort
        int n = 100000;
        int *arr = (int*) malloc(n*sizeof(int));
        srand(time(NULL));
        int r;
        int i = 0;
        int j = 0;
        int d, s;
        while(i < n) {
            d = rand() % 7;
            s = rand() % 10;
            if(s <= 4) { j += d; }
            else { j -= d; }
            arr[i] = j;
            i++;
        }
        // 

        // bắt buộc
        gettimeofday(&tp, NULL);
        start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        //  

        // gọi thuật toán ở đây
        // selection_sort(arr, n);
        // insertion_sort(arr, n);
        // merge_sort(arr, n);
        // heapSort(arr, n);
        // quick_sort(arr, n);
        // quick_sort_3(arr, n);
        // shell_sort(arr, n);
        bubbleSort(arr, n);
        // 

        // bắt buộc
        gettimeofday(&tp, NULL);
        end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        cout << end - start << endl;
        runtime += end - start;
    }
    cout << "runtime = " << runtime / 10;

    return 0;
}