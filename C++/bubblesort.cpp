#include <iostream>
#include <vector>
using namespace std;

//Bubble Sort
//sorting.

vector<int> bubbleSort(vector<int> avector) { //the vector for bubble sort
  for (int passnum = avector.size()-1; passnum > 0; passnum -= 1) {
      for (int i = 0; i < passnum; i++) {
          if (avector[i] > avector[i+1]) {
              int temp = avector[i];
              avector[i] = avector[i+1];
              avector[i+1] = temp;
          }
      }
  }
  return avector;
}

int main() {
    // Vector initialized using a static array
    static const int arr[] = {32,16,97,27,87,38,54,95,73};
    vector<int> avector (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<int> bvector = bubbleSort(avector);
    for (unsigned int i = 0; i < bvector.size(); i++) {
        cout<<bvector[i]<< " ";
    }