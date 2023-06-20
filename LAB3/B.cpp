#include <bits/stdc++.h>

using namespace std;

bool canSplit(long long largest, long long nums[], long long n, long long m)
{
    long long subarr = 0, curSum = 0;
    for (long long i = 0; i < n; i++)
    {
        curSum += nums[i];
        if (curSum > largest)
        {
            subarr += 1;
            curSum = nums[i];
        }
    }
    return subarr + 1 <= m;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    long long a[n], r = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        r += a[i];
    }
    long long l = *max_element(a, a + n);
    long long res = r, mid;
    while (l <= r)
    {
        mid = l + ((r - l) / 2);
        if (canSplit(mid, a, n, k))
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