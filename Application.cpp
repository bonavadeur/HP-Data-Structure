#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <bits/stdc++.h>
#include <chrono>
#include <vector>

#include "CreateInput.h"
#include "Application.h"

using namespace std;
using namespace std::chrono;

// constructor
Application::Application()
    {
        arr = NULL;
        algorithm_result.time = 0;
        algorithm_result.memory = 0;
        algorithm_result.stable_count = 0;
        arr_size = 0;
    };

// input do nguoi dung tao
void Application::createInput(string type, int size) {
  if (size <= 0)
   return ;

  int* buffer= new int[size];
  delete[] arr;
  arr = new struct input[arr_size];
  // raw_arr = (int*)malloc(sizeof(int)*size);
  if (type == InputType[0]) {
    Create_Random_Arr(buffer,size);
  }
  else if (type == InputType[1]) {
    Create_Many_Duplicate_Arr(buffer, size);
  }
  else if (type == InputType[2]) {
    Create_Nearly_Sorted_Arr(buffer,size);
  }  
  else if (type == InputType[3]) {
    Create_Sorted_Arr(buffer, size);
  }
  else if (type == InputType[4]) {
    Create_Reverse_Sorted_Arr(buffer,size);
  }

  ofstream file;
  file.open("Result/Mesuare_Result.txt", std::ios_base::app);
  file << "\n\n\n" << "\t\t\t\t\t\t\t\t\t\tType of input: " << type << "\n\n\n";
  file.close();
  for (int i = 0; i < size; i++) {
    arr[i].value = buffer[i];
    arr[i].idx = i;
    // raw_arr[i] = buffer[i];
    } 
    delete[] buffer;
}

// convert tu file "input.txt" thanh mang, file phai nam cung thu muc voi code
void Application::FileToArr() {
  ifstream InFile;
  InFile.open("input.txt");
  vector<int> numbers;
  int number;

  while(InFile >> number)
      numbers.push_back(number);

  arr_size = numbers.size();
  // raw_arr = (int*)malloc(sizeof(int)*arr_size);
  delete[] arr;
  arr = new struct input[arr_size];

  for (int i = 0; i < arr_size; i++) {
            arr[i].value = numbers[i];
            arr[i].idx = i;
            // raw_arr[i] = numbers[i];
    }  
  
  InFile.close();
}

// write created input by user to file 
void Application::ArrToFile() {
  ofstream OutFile;
  OutFile.open("input.txt");

  for (int i = 0; i < arr_size; i++) {
    if (i%20 == 0 && i != 0) 
      OutFile << arr[i].value << endl;
    else 
      OutFile << arr[i].value << " ";
  } 
  OutFile.close();
}

// chon input: tao tu ban phim hoac lay tu file "input.txt"
void Application::getInput(vector<string> getType) {
  cout << getType[0];
  if (getType[0].compare("create") == 0) {

      this->arr_size = stoi(getType[2]);
      createInput(getType[1],arr_size);
      ArrToFile();
  } 
  else if (getType[0].compare("file") == 0) {
    cout << "Getting input from input.txt ..........." << endl;
    FileToArr();
    cout << "Got " << arr_size << " numbers from input.txt" << endl;
  }
  else {
    return;
  }
}

// chon thuat toan bang ten
void Application::setAlgorithm(SortAlgorithm *algorithm_) {
  delete this->algorithm;
  this->algorithm = algorithm_;
}

SortAlgorithm* Application::nameToAlgorithm(string algorithmName) {
  if ( algorithmName == "bogo") 
    return new BogoSort();
  else if (algorithmName == "selection")
    return new SelectionSort();
  else if (algorithmName == "insertion")
    return new InsertionSort;
  else if (algorithmName == "merge")
    return new MergeSort();
  else if (algorithmName == "heap")
    return new HeapSort();
  else if (algorithmName == "quick")
    return new QuickSort();
  else if (algorithmName == "quick3")
    return new QuickSort3();
  else if (algorithmName == "bubble")
    return new BubbleSort();
  else if (algorithmName == "shell")
    return new ShellSort();
  else 
    return NULL;
}

// print array to screen
void Application::printArr() {
    for (int i = 0; i < arr_size; i++) {
            cout << "(" << arr[i].value << ")" << " ";
    } 
    cout << endl;  
}

// run sort algorithm and mesure time excuting
void Application::resultMesaure(SortAlgorithm* algor) {
        auto start = high_resolution_clock::now();

        // run sort algorithm
        algor->do_algorithm(arr, arr_size);

        auto stop = high_resolution_clock::now();
        auto duration = (stop - start);
        auto us = duration_cast<nanoseconds>(duration);
        algorithm_result.time = static_cast<double>(us.count()) / 1000000;
    }

// print result: sorted array, time, .... to screen
void Application::printResult(SortAlgorithm* algor) {
  cout << "Algorithm " << algor->name_ << endl;
  cout << "Time to sort this array is: " << fixed << algorithm_result.time << "miliseconds" << endl;
  cout << "Memory usage is: " << algorithm_result.memory << endl;
  if (algorithm_result.stable_count == 0) 
    cout << "This algorithm is stable" << endl;
  else {
    cout << "This algorithm is not stable" << endl;
    cout << "Number of changes is: " << algorithm_result.stable_count << endl;
  }
  cout << "Sorted array: " << endl;
  printArr();
}

// write result: sorted array, time, .... to files in "Result" folder, this folder in same folder with source code
void Application::resultToFile(SortAlgorithm* algor) {
  ofstream sorted_array;
  sorted_array.open("Result/Sorted_Array.txt", std::ios_base::app);
  sorted_array << "Algorithm: " << algor->name_ << " sort" << endl;
  for (int i = 0; i < arr_size; i++) {
    if (i%20 == 0 && i != 0) 
      sorted_array << "(" << arr[i].value << ")" << endl;
    else  
      sorted_array << "(" << arr[i].value << ")" << " ";
  }
  sorted_array << endl << endl;
  sorted_array.close();

  ofstream result;
  result.open("Result/Mesuare_Result.txt", std::ios_base::app);
  result << "Algorithm: " << algor->name_ << " sort" << endl;
  result << "Size of input: " << arr_size << " element" << endl;  
  result << "Time to sort this array is: " << fixed << algorithm_result.time << " miliseconds" << endl;
  result << "Memory usage is: " << algorithm_result.memory << endl;
  if (algorithm_result.stable_count == 0) 
    result << "This algorithm is stable" << endl;
  else {
    result << "This algorithm is not stable" << endl;
    result << "Number of changes is: " << algorithm_result.stable_count << endl;
  }
    
  result << "........................................................" << endl;
  result.close();
  cout << "Wrote result to file " << endl << endl;
} 


// check stable of sorted array
void Application::stableCheck() {
  algorithm_result.stable_count = 0;
  int i;
  for(i = 0; i < arr_size; i++) {
    if (arr[i].value == arr[i+1].value) {
      if (arr[i].idx > arr[i+1].idx)
        algorithm_result.stable_count += 1 ;
    }
  }

}

// choose output type: print to screen or write to file
void Application::setOutput(string outputType,SortAlgorithm* algor) {
  if (outputType == "screen") {
    printResult(algor);
  } 
  else if (outputType == "file"){
    resultToFile(algor);
  }
  else 
    return;
}

vector<string> Application::cmd_parsing_input(int argc, char** argv) {

  vector<string> input;

  if(strcmp(argv[1],"file") == 0) {
    input.push_back(argv[1]);
  } 

  else if (strcmp(argv[1],"create") == 0) {
    input.push_back("create");

    for (int i = 0; i < NUMBER_INPUT_TYPE; i++) {

      if (InputType[i].compare(argv[2]) == 0) {
        input.push_back(argv[2]);
      }
    }
    input.push_back(argv[3]);
  }
  return input;
}

vector<string> Application::cmd_parsing_algorithm(int argc, char** argv) {
  vector<string> algor;
  int idx = argc - 1;

  if (strcmp(argv[idx], "all") == 0) {
    for(int i = 0; i < NUMBER_SORT_ALGORITHM; i++) {
      algor.push_back(SortType[i]);
    }
    return algor;
  } 
  else {
    for(int i = 0; i < NUMBER_SORT_ALGORITHM; i++) {
      for (int j = 1; j < argc; j++) {
        if (SortType[i].compare(argv[j]) == 0) {
          algor.push_back(SortType[i]);
        }
      }
    }
    return algor;
  }
  cout << "Invalid algorithm name\n";
  exit(0); 
}

// run application
void Application::run(vector<string> input, vector<string> algorName) {
    // cout << "Enter \"file\" if you want getting input from a file, or \"create\" if you want create input yourself." << endl;
    // string getType;
    // cin >> getType;
    

    getInput(input);

    // cout << "Enter algorithm name (enter \"all\" to run all algorithm): " << endl;
    
  
    // cin >> algorithmName;
    for (auto &name : algorName) {
      FileToArr();
      SortAlgorithm* algor = nameToAlgorithm(name);
      setAlgorithm(algor);
      cout << "Sorting ..............." << endl;
      cout << algor->name_ << endl;
      resultMesaure(algor);
      cout << "Array is sorted" << endl;
      stableCheck();
      // cout << "Enter \"Screen\" to print result to screen, \"File\" to write result to text file" << endl;
      // string outType;
      // cin >> outType;
      setOutput("file",algor);
      
    }
    
}