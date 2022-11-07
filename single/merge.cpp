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
void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Tạo các mảng tạm
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy dữ liệu sang 2 mảng tạm
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];
    // Gộp 2 mảng tạm vừa rồi và mảng arr
	auto indexOfSubArrayOne = 0, // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
		indexOfSubArrayTwo = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	int indexOfMergedArray = left; // Khởi tạo chỉ số bắt đầu của mảng lưu kết quả

	// Hợp nhất mảng tạm thời lại thành mảng [left..right]
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
	// Copy các phần tử còn lại của mảng left vào arr nếu có
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy các phần tử còn lại của mảng right vào arr nếu có
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Trả về đệ quy

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}
void merge_sort(int a[], int n) {
    mergeSort(a, 0, n-1);
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
        merge_sort(arr, n);
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