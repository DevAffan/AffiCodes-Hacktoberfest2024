#include<iostream>
using namespace std;

int main()
{
    int a[100], i, j, n, t;
    cout << "Array size : ";
    cin >> n;
    cout << "Enter array elements : ";
    for(i = 0; i < n; i++)
        cin >> a[i];
        
    cout << "Array elements : " << endl;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
        
    cout << endl;

    for(i = 0; i < n - 1; i++)                     
        for(j = i + 1; j < n; j++)
        {
            if(i % 2)  
            {
                if(a[i] > a[j])
                    a[i] = a[i] + a[j] - (a[j] = a[i]);
            }
            else  
            {
                if(a[i] < a[j])   
                    a[i] = a[i] + a[j] - (a[j] = a[i]);
            }
        }
        
    cout << "Array elements : " << endl;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
        
    cout << endl;
    
    return 0;
}
