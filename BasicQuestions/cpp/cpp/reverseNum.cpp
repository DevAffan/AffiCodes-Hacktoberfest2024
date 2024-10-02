#include<iostream>
using namespace std;

int reverseNum(int num){
    int reverse = 0;
    while(num>0){
        reverse+= (num%10);
        reverse*=10;
        num/=10;
    }
    reverse/=10;
    return reverse;
}

int main(){
    int n;
    cin>>n;
    cout<<reverseNum(n);
    return 0;
}