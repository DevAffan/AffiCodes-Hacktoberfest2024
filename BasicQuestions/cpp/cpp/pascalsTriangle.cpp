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

    int row;
    cout<<"Enter number of rows: ";
    cin>>row;
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            cout<<calcNCR(i,j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}