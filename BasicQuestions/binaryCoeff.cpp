#include<iostream>
using namespace std;

int factRec(int num){
    if(num==0 || num==1){
        return 1;
    }
    else{
        return num*factRec(num-1);
    }
}

int calcNCR(int n, int r){
    int ans = factRec(n)/(factRec(r)*factRec(n-r));
    return ans;
}

int main(){
    int n,r;
    cout<<"Enter the values for n and r respectively: ";
    cin>>n>>r;
    cout<<"Value of nCr: "<<calcNCR(n,r);
    return 0;
}