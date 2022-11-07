#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<sys/time.h>
#include<stdlib.h>

using namespace std;



void swap(int &xp, int &yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int arr[], int n) {
    int i, j, minIdx;
    for (int i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
        // printArray(arr, n);
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

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

int main() {
    system("cls");

    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    // int arr[] = {64, 25, 12, 22, 11};
    int n = 20;
    int arr[n];
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

    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // int *arr = (int*) malloc(100*sizeof(int));
    // for(int i = 0; i < n/2; i++) {
    //     arr[i] = random(1, n * 10);
    // }
    // int n = sizeof(arr) / sizeof(arr[0]);
    // printArray(arr, n);
    // selection_sort(arr, n);
    // insertion_sort(arr, n);
    // printf("Sorted array: \n");
    // printArray(arr, n);

    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << end - start;

    return 0;
}