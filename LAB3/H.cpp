#include <bits/stdc++.h>

using namespace std;

int binSearch(int a[], int n, int m)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] == m)
            return mid;
        if (a[mid] > m)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int lines[n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        lines[i] = sum;
    }

    while (m--)
    {
        int mi;
        cin >> mi;
        cout << binSearch(lines, n, mi) + 1 << "\n";
    }
}