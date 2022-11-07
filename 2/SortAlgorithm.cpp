#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>

#include "SortAlgorithm.h"

using namespace std;

void swap(struct input &xp, struct input &yp) {
    struct input temp = xp;
    xp = yp;
    yp = temp;
}

void swap2(struct input* a, struct input* b) {
	struct input t = *a;
	*a = *b;
	*b = t;
}

/**
 * SortAlgorithm class
 */
SortAlgorithm::SortAlgorithm() {};

void SortAlgorithm::do_algorithm (struct input arr[], int size) {
            algorithm(arr, size);
        }
/*end SortAlgorithm class*/

/**
 * BogoSort class
 */
BogoSort::BogoSort(): SortAlgorithm() {name_ = "bogo";};

int BogoSort::is_sorted(struct input arr[], int size) {
    while ( --size >= 0 ) {
        if ( arr[size].value < arr[size-1].value ) {
            return false;
        }
    }
    return 1;
}

// void BogoSort::shuffle(struct input arr[], int size) {
//     int r;
//     struct input temp;
//     for(int i=0; i < size; i++) {
//         temp = arr[i];
//         r = random() % size;
//         arr[i] = arr[r];
//         arr[r] = temp;
//     }
// }

void BogoSort::algorithm (struct input arr[], int size) {
    while ( !is_sorted(arr, size) ) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

        for (int i = 1; i < size; i++)
            swap(arr[i], arr[uniform_int_distribution<int>(0, i)(rng)]);
    }
}
/*end BogoSort class*/

/**
 * InsertionSort class
 */
InsertionSort::InsertionSort(): SortAlgorithm() {name_ = "insertion";};

void InsertionSort::algorithm(struct input arr[], int size) {
    int i, j;
    struct input key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j].value > key.value)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
/*end InsertionSort class*/

/**
 * SelectionSort class
 */
SelectionSort::SelectionSort(): SortAlgorithm() {name_ = "selection";};

void SelectionSort::algorithm(struct input arr[], int size) {
    int i, j, minIdx;
    for (int i = 0; i < size - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < size; j++)
            if (arr[j].value < arr[minIdx].value)
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}
/*end SelectionSort class*/

/**
 * BubbleSort class
 */
BubbleSort::BubbleSort(): SortAlgorithm() {name_ = "bubble";};

void BubbleSort::algorithm(struct input arr[], int size) {
    int i, j; 
    for (i = 0; i < size-1; i++)         
       for (j = 0; j < size-i-1; j++)  
           if (arr[j].value > arr[j+1].value) 
              swap(arr[j], arr[j+1]); 
}
/*end BubbleSort class*/

/**
 * ShellSort class
 */
ShellSort::ShellSort(): SortAlgorithm() {name_ = "shell";};

void ShellSort::algorithm(struct input arr[], int size) {
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i += 1) {
            struct input temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval].value > temp.value; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}
/*end ShellSort class*/

/**
 * MergeSort class
 */
MergeSort::MergeSort(): SortAlgorithm() {name_ = "merge";};

void MergeSort::merge(struct input arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    /* Tạo các mảng tạm */
    struct input* L = new struct input[n1], *R = new struct input[n2];
    /* Copy dữ liệu sang các mảng tạm */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    /* Gộp hai mảng tạm vừa rồi vào mảng arr*/
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2)
    {
        arr[k++] = L[i].value <= R[j].value ? L[i++] : R[j++];
    }
    /* Copy các phần tử còn lại của mảng L vào arr nếu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy các phần tử còn lại của mảng R vào arr nếu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void MergeSort::mergeSort(struct input arr[], int begin, int end)
{
	if (begin >= end)
		return; // Trả về đệ quy

	int m = begin + (end - begin) / 2;
	mergeSort(arr, begin, m);
	mergeSort(arr, m + 1, end);
	merge(arr, begin, m, end);
}

void MergeSort::algorithm(struct input arr[], int size) {
    if (size < 2) return;
	mergeSort(arr, 0, size - 1);
}
/*end MergeSort class*/

/**
 * HeapSort class
 */
HeapSort::HeapSort(): SortAlgorithm() {name_ = "heap";};

void HeapSort::heapify(struct input arr[], int size, int i) {
    int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < size && arr[l].value > arr[largest].value)
		largest = l;
	if (r < size && arr[r].value > arr[largest].value)
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, size, largest);
	}
}

void HeapSort::algorithm(struct input arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
/*end HeapSort class*/

/**
 * QuickSort class
 */
QuickSort::QuickSort(): SortAlgorithm() {name_ = "quick";};

void QuickSort::quickSort(struct input arr[], int low, int high) {
    struct input pivot = arr[high];
	int i = low-1, j = high;
	if (high <= low) return;

	while (1)
	{
		while (arr[++i].value < pivot.value) ;
		while (pivot.value < arr[--j].value) if (j == low) break;
		if (i >= j) break;
		swap2(&arr[i], &arr[j]);
	}
	swap2(&arr[i], &arr[high]);
	quickSort(arr, low, i - 1);
	quickSort(arr, i + 1, high);
}

void QuickSort::algorithm(struct input arr[], int size) {
    quickSort(arr, 0, size-1);
}
/*end QuickSort class*/

/**
 * QuickSort3 class
 */
QuickSort3::QuickSort3(): SortAlgorithm() {name_ = "quick3";};

void QuickSort3::quickSort3(struct input arr[], int low, int high) {
    int i = low -1, j = high, p = low - 1, q = high;
	struct input pivot = arr[high];
	if (low >= high)
		return;
	while (1)
	{
		while (arr[++i].value < pivot.value) ;
		while (pivot.value < arr[--j].value) if (j == low) break;
		if (i >= j) break;
		swap2(&arr[i], &arr[j]);
		if (arr[i].value == pivot.value) swap2(&arr[++p], &arr[i]);
		if (arr[j].value == pivot.value) swap2(&arr[j], &arr[--q]);
	}

	swap2(&arr[i], &arr[high]);
	j = i-1; i++;
	for(int k = low; k < p; k++, j--) swap2(&arr[k], &arr[j]);
	for(int k = high - 1; k > q; k--, i++) swap2(&arr[i], &arr[k]);

	// Recur two halves
	quickSort3(arr, low, j);
	quickSort3(arr, i, high);
}

void QuickSort3::algorithm(struct input arr[], int size) {
    quickSort3(arr, 0, size-1);
}
/*end QuickSort3 class*/








