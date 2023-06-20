#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target;
    cin >> target;
    int l = 0, r = n - 1;
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] == target)
        {
            cout << "Yes";
            return 0;
        }
        else if (a[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << "No";
}