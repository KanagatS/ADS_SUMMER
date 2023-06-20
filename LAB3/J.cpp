#include <bits/stdc++.h>

using namespace std;

bool canSteal(int nums[], int h, int n, int mid)
{
    int totalH = 0;
    for (int i = 0; i < n; i++)
    {
        totalH += (nums[i] + mid - 1) / mid;
    }
    if (totalH > h)
        return false;
    else
        return true;
}

int main()
{
    int n, h;
    cin >> n >> h;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int r = *max_element(a, a + n);
    int l = 1, mid, res;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (canSteal(a, h, n, mid))
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