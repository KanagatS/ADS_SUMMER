#include <bits/stdc++.h>

using namespace std;

bool canGive(int a[], int n, int f, int mid)
{
    int totalFlights = 0;
    for (int i = 0; i < n; i++)
    {
        totalFlights += (a[i] + mid - 1) / mid;
    }
    if (totalFlights <= f)
        return true;
    else
        return false;
}

int main()
{
    int n, f;
    cin >> n >> f;
    int children[n];
    for (int i = 0; i < n; i++)
    {
        cin >> children[i];
    }
    int l = 1, r = *max_element(children, children + n);
    int mid, res;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (canGive(children, n, f, mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res;
}