#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n][4];
    int max_l = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        int local_max = *max_element(arr[i], arr[i] + 4);
        if (local_max > max_l)
            max_l = local_max;
    }
    int l = 1, r = max_l, mid, res;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid >= arr[i][0] && mid >= arr[i][1] && mid >= arr[i][2] && mid >= arr[i][3])
                cnt++;
        }
        if (cnt >= k)
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