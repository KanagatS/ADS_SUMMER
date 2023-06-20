#include <bits/stdc++.h>

using namespace std;

int binSearch(int a[], int n, int pow)
{
    int l = 0, r = n - 1;
    int mid, res;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] > pow)
            r = mid - 1;
        else
        {
            res = l;
            l = mid + 1;
        }
    }
    return l;
}

int sum(int a[], int l)
{
    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += a[i];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    int r;
    cin >> r;
    while (r--)
    {
        int pow;
        cin >> pow;
        int index = binSearch(nums, n, pow);
        int s = sum(nums, index);
        cout << index << " " << s << "\n";
    }
}