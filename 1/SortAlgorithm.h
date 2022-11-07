#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <fstream>

using namespace std;

struct input {
  int value;
  int idx;
};

void swap2(int* , int* );

// vituarl sort algorithm class
class SortAlgorithm
{
    public:
        SortAlgorithm();
        string name_;
        // void SetName(string name);
        void do_algorithm (struct input arr[], int size);   
    private:
        virtual void algorithm(struct input arr[], int size) = 0;
};

// bogo sort class
class BogoSort: public SortAlgorithm
{
    public:
        BogoSort();
    private:

        int is_sorted(struct input arr[], int size);
        
        // void shuffle(struct input arr[], int size);

        void algorithm (struct input arr[], int size);
};

// insertion sort class
class InsertionSort: public SortAlgorithm
{
    public:
        InsertionSort();
    private:
        void algorithm (struct input arr[], int size);
};

// selection sort class
class SelectionSort: public SortAlgorithm
{
    public:
        SelectionSort();
    private:
        void algorithm (struct input arr[], int size);
};

// bubble sort class
class BubbleSort: public SortAlgorithm
{
    public:
        BubbleSort();
    private:
        void algorithm (struct input arr[], int size);
};

// shell sort class
class ShellSort: public SortAlgorithm
{
    public:
        ShellSort();
    private:
        void algorithm (struct input arr[], int size);
};

// merge sort class
class MergeSort: public SortAlgorithm
{
    public:
        MergeSort();
    private:
        void mergeSort(struct input arr[], int begin, int end);
        void merge(struct input arr[], int l, int m, int r);
        void algorithm (struct input arr[], int size);
};

// heap sort class
class HeapSort: public SortAlgorithm
{
    public:
        HeapSort();
    private:
        void heapify(struct input arr[], int size, int i);
        void algorithm (struct input arr[], int size);
};

// quick sort class
class QuickSort: public SortAlgorithm
{
    public:
        QuickSort();
    private:
        void quickSort(struct input arr[], int low, int high);
        void algorithm (struct input arr[], int size);
};

// quick sort 3 class
class QuickSort3: public SortAlgorithm
{
    public:
        QuickSort3();
    private:
        void quickSort3(struct input arr[], int low, int high);
        void algorithm (struct input arr[], int size);
};
