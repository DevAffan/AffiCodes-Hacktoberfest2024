#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
};

int Compare_X(const void *n1, const void *n2)
{
    Point *p1 = (Point *)n1, *p2 = (Point *)n2;
    return (p1->x != p2->x) ? (p1->x - p2->x) : (p1->y - p2->y);
}

int Compare_Y(const void *n1, const void *n2)
{
    Point *p1 = (Point *)n1, *p2 = (Point *)n2;
    return (p1->y != p2->y) ? (p1->y - p2->y) : (p1->x - p2->x);
}

float distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float BruteForce(Point P[], int n)
{
    float min1 = FLT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (distance(P[i], P[j]) < min1)
                min1 = distance(P[i], P[j]);
        }
    }
    return min1;
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}

float Strip_Closest(Point strip[], int size, float d)
{
    float min2 = d;
    qsort(strip, size, sizeof(Point), Compare_Y);

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min2; j++)
        {
            if (distance(strip[i], strip[j]) < min2)
                min2 = distance(strip[i], strip[j]);
        }
    }

    return min2;
}

float closest_sub(Point P[], int n)
{
    if (n <= 3)
        return BruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    float d_left = closest_sub(P, mid);
    float d_right = closest_sub(P + mid, n - mid);

    float d = min(d_left, d_right);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
    }

    return min(d, Strip_Closest(strip, j, d));
}

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), Compare_X);

    return closest_sub(P, n);
}

int main()
{
    int n;
    cout << "Enter the number of points you want to enter: ";
    cin >> n;
    Point Arr_Points[n];

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "Enter the coordinates(x y) of the point " << i + 1 << ": ";
        cin >> Arr_Points[i].x >> Arr_Points[i].y;
    }

    cout << "\nThe Closest Distance between the two points from the set is " << closest(Arr_Points, n) << endl;
    return 0;
}