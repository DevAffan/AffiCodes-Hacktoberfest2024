#include<iostream>
using namespace std;
int main()
{
    int A[10] , n = 5 , l = 0 , h = n - 1 , mid , key;
    cout<<"Enter elements:";
    for(int i = 0 ; i < n ; i ++)
    {
        cin>>A[i];
    }
    cout<<"Enter key element:";
    cin>>key;
    while (l<=h)
    {
        mid = (l + h )/2;
        if(key == A[mid])
        {
            cout<<"Found at "<<mid;
            return 0;
        }
        else if(key<A[mid])
        h = mid - 1;
        else
        l = mid + 1;
    }

     cout<<"Not found";
    
    return 0;
}