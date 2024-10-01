#include<bits/stdc++.h>
using namespace std;

int* minMax(int arr[], int n){
    int* a=new int[2];
    int minNo=arr[0],maxNo=arr[0];
    for(int i=1;i<n;i++){
        minNo = min(minNo, arr[i]);
        maxNo = max(maxNo, arr[i]);
    }
    a[0]=minNo;
    a[1]=maxNo;
    return a;
}

int main(){
    int n ;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    int*a= minMax(arr,n);
    cout<<"min: "<<a[0]<<endl;
    cout<<"max: "<<a[1]<<endl;

    return 0;
}