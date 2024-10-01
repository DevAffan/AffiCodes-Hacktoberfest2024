#include<iostream>
using namespace std;


void fibb(int n){
    int a =0, b=1;
    int nextTerms;
    cout<<"The fibbonacci series: ";
    while (n>0){
        cout<<a<<" ";
        nextTerms = a+b;
        a=b;
        b=nextTerms;
        n--;
    }
}

int main(){
    int nTerms;
    cout<<"Enter the number of terms you want: ";
    cin>>nTerms;
    fibb(nTerms);
    return 0;
}