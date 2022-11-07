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

// đoạn này tuỳ thuật toán copy được trên gg
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void quickSort(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = low-1, j = high;
	if (high <= low) return;

	while (1)
	{
		while (arr[++i] < pivot) ;
		while (pivot < arr[--j]) if (j == low) break;
		if (i >= j) break;
		swap(&arr[i], &arr[j]);
	}
	swap(&arr[i], &arr[high]);
	quickSort(arr, low, i - 1);
	quickSort(arr, i + 1, high);
}

void quick_sort(int arr[], int n) {
    quickSort(arr, 0, n-1);
}
// 

int main() {
    system("cls");

    // bắt buộc
    struct timeval tp;
    int time = 10;
    long int start, end;
    
    for(int loop = 0; loop < 10; loop++) {
        // đoạn này sinh n phần tử ngẫu nhiên trong khoảng 0->10n
        // thống nhất test n = 100000
        int n = 100000;
        int *arr = (int*) malloc(n*sizeof(int));
        for(int i = 0; i < n; i++) {
            arr[i] = random(1, n * 10);
        }
        // 

        // bắt buộc
        gettimeofday(&tp, NULL);
        start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        //  

        // gọi thuật toán ở đây
        quick_sort(arr, n);
        // 

        // bắt buộc
        gettimeofday(&tp, NULL);
        end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        cout << end - start << endl;
        time += end - start;
    }
    cout << "runtime = " << time / 10;

    return 0;
}