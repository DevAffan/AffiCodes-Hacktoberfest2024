#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            cout<<"non-prime";
            return false;
        }
    }
    cout<<"Prime";
    return true;
}

int main(){
    int num;
    cin>>num;
    isPrime(num);
    return 0;
}
