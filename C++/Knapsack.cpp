#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int Knapsack(int wt[], int val[], int W, int n) {

	if (n == 0 || W == 0) //Base Case
		return 0;

	// if Already calculated
	if (dp[n][W] != -1)
		return dp[n][W];
  
	// else calculate
	else {
		if (wt[n-1] <= W) //dp[n][w] will be maximum of case if we take or not take 
			dp[n][W] = max(val[n-1] + Knapsack(wt, val, W - wt[n-1], n-1),Knapsack(wt, val, W, n-1));

		else if (wt[n-1] > W) //It is not possible to take so new value remains same as of n-1 objects
			dp[n][W] = Knapsack(wt, val, W, n - 1);

		return dp[n][W];
	}
}

int main() {
	int n,W;
    cout<<"Enter number of objects: ";
    cin >> n;

	int val[n], wt[n];  // Values and weights array
    cout<<"Enter weights seperated by spaces"<<endl;

	for (int i = 0; i < n; i++){
		cin >> wt[i]; //Take input of weight array
    }
    cout<<"Enter respective Values seperated by spaces"<<endl;

	for (int i = 0; i < n; i++){
		cin >> val[i]; //Take input of value array 
    }
    cout<<"Enter maximum capacity of knapsack : ";
    cin >> W; // Max capacity

    // DP matrix initialization with -1
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= W; j++)
			dp[i][j] = -1;
    
	cout <<"Maximum value that the knapsack can store is "<< Knapsack(wt, val, W, n) << endl;
	return 0;
}