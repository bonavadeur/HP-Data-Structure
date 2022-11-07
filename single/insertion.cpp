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
// 

int main() {
    system("cls");

    // bắt buộc
    struct timeval tp;
    int time = 0;
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
        insertion_sort(arr, n);
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