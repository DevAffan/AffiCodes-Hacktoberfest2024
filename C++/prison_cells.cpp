#include <iostream>
#include <map>
#include <vector>
using namespace std;

/* 
Leetcode: 957. Prison Cells After N Days
There are 8 prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.

You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.

Return the state of the prison after n days (i.e., n such changes described above).


Example 1:

Input: cells = [0,1,0,1,1,0,0,1], n = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]


Example 2:

Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
Output: [0,0,1,1,1,1,1,0]

*/
std::vector<int> prisonAfterNDays(std::vector<int>&& cells, int n) {
    std::map<std::vector<int>, int> history;
    int period = -1;
    for (int j = 1; j <= 32 && period == -1; j++) {
        int temp = cells[0];
        cells[0] = 0; 
        for (size_t i = 1; i < 7; i++){
            int save = cells[i];
            //printf("i = %d, (i-1, i, i+1) = (%d, %d, %d)\n", i, temp, cells[i], cells[i+1]);
            cells[i] = (temp == cells[i + 1] ? 1 : 0);
            temp = save;
        }   
        cells[7] = 0;
        
        // If key not found in map iterator to end is returned
        if (history.find(cells) == history.end()) {
            history.insert({cells, j});  
        } else {
            period = j - 1;
        }
    }
    int remainder = n % period == 0 ? period :  n % period;
    //cout << "Period = " << period << " " << " Remainder=" << remainder;
    for (auto it = history.begin(); it != history.end(); ++it) {
        if (it->second == remainder)
            cells = it->first;
    }
    
    return cells;
}

int main(int argc, char **argv) {
  const auto output_1 = prisonAfterNDays(std::vector<int>{0,1,0,1,1,0,0,1}, 7);
  for(const auto& element: output_1) std::cout << element << " ";
  std::cout <<std::endl;
  const auto output_2 = prisonAfterNDays(std::vector<int>{1,0,0,1,0,0,1,0}, 1000000000);
  for(const auto& element: output_2) std::cout << element << " ";
  std::cout <<std::endl;
  return 0;
}