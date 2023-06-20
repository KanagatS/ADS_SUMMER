#include <bits/stdc++.h>

using namespace std;

int snake[800][800];

int binaryInc(int v[], int target, int m)
{
    int l = 0, r = m - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == target)
            return mid;
        else if (target < v[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int binaryDec(int v[], int target, int m)
{
    int l = 0, r = m - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == target)
            return mid;
        else if (target < v[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int findRow(int v[][800], int target, int n, int m)
{
    int l = 0, r = n - 1, mid, min, max;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (mid % 2 == 0)
        {
            min = v[mid][m - 1];
            max = v[mid][0];
        }
        else
        {
            min = v[mid][0];
            max = v[mid][m - 1];
        }
        if (target >= min && target <= max)
        {
            return mid;
        }
        else if (target < min)
            l = mid + 1;
        else if (target > max)
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    vector<int> v(t);
    for (int i = 0; i < t; i++)
        cin >> v[i];
    int m, n;
    cin >> n >> m;
    // int snake[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> snake[i][j];
        }
    }
    for (int i = 0; i < t; i++)
    {
        int res;
        int row = findRow(snake, v[i], n, m);
        if (row == -1)
        {
            cout << -1 << "\n";
            continue;
        }
        if (row % 2 == 0)
            res = binaryDec(snake[row], v[i], m);
        else
            res = binaryInc(snake[row], v[i], m);
        if (res != -1)
            cout << row << " " << res << "\n";
        else
            cout << -1 << "\n";
    }
}