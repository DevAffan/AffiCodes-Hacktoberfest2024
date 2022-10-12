#include <iostream>
using namespace std;
int binarysearch(int *a, int n, int x)
{
    // Intialize start as the start point
    // end as the end of an array
    // Mid variable to be search in an array.
    int start = 0;
    int end = n - 1;
    int mid;
    while (end >= start)
    {
        mid = (start + end) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    // Input the size of an array.
    int n;
    cin >> n;
    //created a Dynamic Array.
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Input the number to search in an array.
    int x;
    cin >> x;
    cout << binarysearch(a, n, x);
    delete[] a;
}
