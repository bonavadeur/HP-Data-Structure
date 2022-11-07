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

void quickSort3(int a[], int low, int high)
{
	int i = low -1, j = high, p = low - 1, q = high;
	int pivot = a[high];
	if (low >= high) // 1 or 0 elements
		return;
	// To handle 2 elements
	while (1)
	{
		while (a[++i] < pivot) ;
		while (pivot < a[--j]) if (j == low) break;
		if (i >= j) break;
		swap(&a[i], &a[j]);
		if (a[i] == pivot) swap(&a[p++], &a[i]);
		if (a[j] == pivot) swap(&a[j], &a[q--]);
	}

	swap(&a[i], &a[high]);
	j = i-1; i++;
	for(int k = low; k < p; k++, j--) swap(&a[k], &a[j]);
	for(int k = high - 1; k > q; k--, i++) swap(&a[i], &a[k]);

	// Recur two halves
	quickSort3(a, low, j);
	quickSort3(a, i, high);
}

void quick_sort_3(int arr[], int n) {
    quickSort3(arr, 0, n-1);
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
        quick_sort_3(arr, n);
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