#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>> n;
    int sum=(n*(n+1))/2; // using formula
    // for(int i=1;i<=n;i++){
    //     sum+=i;
    // }
    cout<<"Sum of "<<n<<" natural numbers are: "<<sum;
    return 0;
}