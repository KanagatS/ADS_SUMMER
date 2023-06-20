#include <bits/stdc++.h>

using namespace std;

struct Heap
{
    long long *a;
    long long capacity;
    long long size;

    long long parent(long long i)
    {
        return (i - 1) / 2;
    }

    long long left(long long i)
    {
        return i * 2 + 1;
    }

    long long right(long long i)
    {
        return i * 2 + 2;
    }

    void heapUp(long long i)
    {
        if (i > 0)
        {
            long long p = parent(i);
            if (a[i] < a[p])
            {
                swap(a[i], a[p]);
                heapUp(p);
            }
        }
    }

    void heapDown(long long i)
    {
        long long l = left(i);
        long long r = right(i);
        long long min = i;
        if (l < this->size && a[min] > a[l])
        {
            min = l;
        }
        if (r < this->size && a[min] > a[r])
        {
            min = r;
        }
        if (min != i)
        {
            swap(a[i], a[min]);
            heapDown(min);
        }
    }

    void add(long long x)
    {
        a[size] = x;
        size++;
        heapUp(size - 1);
    }

    void cut_min()
    {
        a[0] = a[size - 1];
        size = max((long long)0, size - 1);
        heapDown(0);
    }

    Heap(long long x)
    {
        a = new long long[x];
        this->capacity = x;
        this->size = 0;
    }
};

int main()
{
    long long n, m;
    cin >> n >> m;
    Heap H(n);
    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        H.add(a);
    }
    long long cnt = 0;
    while (H.a[0] <= m)
    {
        if (H.size < 2)
        {
            cout << -1;
            return 0;
        }
        long long minFirst = H.a[0];
        H.cut_min();
        long long minSecond = H.a[0];
        H.cut_min();
        H.add(minFirst + 2 * minSecond);
        cnt++;
    }
    cout << cnt;
}