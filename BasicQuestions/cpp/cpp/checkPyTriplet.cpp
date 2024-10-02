#include<iostream>
using namespace std;

bool check(int x, int y, int z){
    int a = max(x, max(y,z));
    int b,c;
     if(a==x){
        b=y;
        c=z;
     }
     else if(a==y){
        b=x;
        c=z;
     }
     else{
        b=y;
        c=x;
     }
     if(a*a == b*b + c*c){
        return true;
     }
     return false;
}

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    if(check(x,y,z)){
        cout<<"Pythagorean Triplet";
    }
    else{
        cout<<"Not Pythagorean Triplet";
    }
    return 0;
}