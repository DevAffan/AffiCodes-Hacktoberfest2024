#include<bits/stdc++.h>
using namespace std;

int main(){
    int n =15; // initial amount

    int nTotal = n; 
    int spare = n%3; //0
    while(n>0){
        spare+=n%3; // 0 2 3
        n/=3; //15 5 1 0
        nTotal+=n;
        if(spare>=3){
            n=3;
            spare=0;
        } // 15 20 21
    }
    int cost = 1; // cost of each chocolate

    cout<<"Therefore total number of chocolate that can be bought is: "<<(nTotal/cost);

    return 0;
}