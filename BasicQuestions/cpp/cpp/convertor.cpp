// #include<iostream>
// #include<string>
#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n){
    int ans =0;
    int x=1;
    while (n>0){
        int y=n%10;
        ans+= x*y;
        x*=2;
        n/=10;
    }
    return ans;
}

int octalToDecimal(int n){
    int ans =0;
    int x=1;
    while (n>0){
        int y=n%10;
        ans+= x*y;
        x*=8;
        n/=10;
    }
    return ans;
}

int hexaDecimalToDecimal(string n){
    int ans =0;
    int x =1;
    int s = n.size();

    for(int i= s-1;i>=0;i--){
        if(n[i] >= '0' && n[i] <= '9'){
            ans += x*(n[i] - '0');
        }
        else if(n[i] >= 'A' && n[i] <= 'F'){
            ans+= x*(n[i]-'A' + 10);
        }
        x*=16;
    }
    return ans;
}

int decimalToBinary(int n){
    // to be completed later...
}

int main(){

    string n;
    cin>>n;
    cout<<decimalToBinary(n)<<endl;
    // cout<<hexaDecimalToDecimal(n)<<endl;
    // cout<<octalToDecimal(n)<<endl;
    // cout<<binaryToDecimal(n)<<endl;

    return 0;
}
