#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dirX[4] = {0, 1, 0, -1}; 
        int dirY[4] = {1, 0, -1, 0}; 
        int x = 0, y = 0;  
        int dir = 0;     
        for(char ch : instructions) {
            if(ch == 'G') {
                x += dirX[dir];
                y += dirY[dir];
            } else if(ch == 'L') { 
                dir = (dir + 3) % 4;  
            } else if(ch == 'R') { 
                dir = (dir + 1) % 4;  
            }
        }
        return (x == 0 && y == 0) || (dir != 0);
    }
};