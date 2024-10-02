#include<iostream>
using namespace std;

// without recursion
int fact(int num){
    int fact =1;
    while(num>=1){
        fact*=num;
        num--;
    }
    return fact;
}

// with recursion
int factRec(int num){
    if(num==0 || num==1){
        return 1;
    }
    else{
        return num*factRec(num-1);
    }
}

int main(){
    int n, ans = 1;
    cout<<"Enter the number to find it's factorial: ";
    cin>> n;
    cout<<"Factorial of "<<n<<" using loop is: ";
    cout<<fact(n)<<endl;
    cout<<"Factorial of "<<n<<" using recursion is: ";
    cout<<factRec(n)<<endl;
    return 0;
}