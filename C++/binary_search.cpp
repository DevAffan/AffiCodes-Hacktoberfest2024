#include <iostream>
using namespace std;
int binarysearch(int *a, int n, int x)
{
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
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << binarysearch(a, n, x);
    delete[] a;
}