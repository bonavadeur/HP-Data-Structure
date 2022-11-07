#include <iostream>
#include <string.h>
#include <algorithm>
#include <ctime>
#include <random>

#include "CreateInput.h"
#include <bits/stdc++.h>

using namespace std;

static std::random_device rd; // random device engine, usually based on /dev/random on UNIX-like systems
// initialize Mersennes' twister using rd to generate the seed
static std::mt19937 rng{rd()}; 


bool comp(const int a, const int b){
   return a > b;
};

int random(int minN, int maxN){
    static std::uniform_int_distribution<int> uid(minN,maxN); 
    return uid(rng); // use rng as a generator
}

void Create_Random_Arr (int *arr, int size) {
  // arr = new int[size];
  for (int i = 0; i < size; i++) {
    arr[i] = random(1,size*10);
  }
  
}

void Create_Nearly_Sorted_Arr (int *arr, int size) {
  // arr = new int[size];
  Create_Random_Arr(arr, size);
  sort(arr,arr+size);
  int seed = (int)log(size);

  for (int i = 0; i < seed; i++) {
    // srand((unsigned int)time(NULL));
    // int ran_idx = random(1,size);
    int ran_idx = 2*i+1;
    int temp = arr[ran_idx - 1] ;
    arr[ran_idx - 1] = arr[ran_idx];
    arr[ran_idx] = temp;
  }
  
}

void Create_Many_Duplicate_Arr (int *arr, int size) {
  // arr = new int[size];
  int seed = (int)size/4;
  if (size < 4) seed = 1;

  for (int i = 0; i < size; i++) {
    // srand(i);
    arr[i] = random(1,size);
    arr[i] %= seed;
  }
  
}

void Create_Sorted_Arr (int *arr, int size) {
  // arr = new int[size];
  Create_Random_Arr(arr, size);
  sort(arr,arr+size);
}

void Create_Reverse_Sorted_Arr (int *arr, int size) {
  // arr = new int[size];
  Create_Random_Arr(arr, size);
  sort(arr,arr+size,comp);
}