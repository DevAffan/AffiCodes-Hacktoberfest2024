#include <iostream>
#include <vector>
using namespace std;

//function goes through list sorting adjacent values as it bubbles
//the largest value to the top.
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
    static const int arr[] = {54,26,93,17,77,31,44,55,20};
    vector<int> avector (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    vector<int> bvector = bubbleSort(avector);
    for (unsigned int i = 0; i < bvector.size(); i++) {
        cout<<bvector[i]<< " ";
    }