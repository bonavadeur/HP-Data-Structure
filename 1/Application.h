#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <vector>

#include "CreateInput.h"
#include "SortAlgorithm.h"

using namespace std;

const string SortType[] = {"shell", "merge", "heap", "quick", "quick3", "bubble", "selection", "insertion"};
const string InputType[] = {"random", "duplicated", "nsorted", "sorted", "rsorted"};
enum CreateType {Random, Many_Duplicate, Nearly_Sorted, Sorted, Reverse_Sorted }; 

#define NUMBER_SORT_ALGORITHM 8
#define NUMBER_INPUT_TYPE 5

struct result {
  double time;
  int64_t memory;
  int stable_count;
};

class Application
{
  public:
    Application();
    void createInput(string type, int size); // ok
    void getInput(vector<string> getType); // ok
    void FileToArr(); 
    void ArrToFile();
    void setAlgorithm(SortAlgorithm *Type); // ok
    SortAlgorithm* nameToAlgorithm(string algorithmName);
    void resultToFile(SortAlgorithm* algor);
    // void sortedArrToFile();
    void setOutput(string outputType,SortAlgorithm* algor); 
    void printArr();//ok
    // void printRawArr();
    void resultMesaure(SortAlgorithm* algor); //ok
    void stableCheck();
    void printResult(SortAlgorithm* algor);
    vector<string> cmd_parsing_input(int argc, char** argv);
    vector<string> cmd_parsing_algorithm(int argc, char** argv);
    void run(vector<string> input, vector<string> algorName);
  private:
    struct input *arr;
    int *raw_arr;
    int arr_size;
    SortAlgorithm* algorithm;
    struct result algorithm_result;
    
};