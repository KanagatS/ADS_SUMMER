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
            if (a[i] > a[p])
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
        long long max = i;
        if (l < this->size && a[max] < a[l])
        {
            max = l;
        }
        if (r < this->size && a[max] < a[r])
        {
            max = r;
        }
        if (max != i)
        {
            swap(a[i], a[max]);
            heapDown(max);
        }
    }

    void add(long long x)
    {
        a[size] = x;
        size++;
        heapUp(size - 1);
    }

    void cut_max()
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
    long long n, x;
    cin >> n >> x;
    Heap H(n);
    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        H.add(a);
    }
    long long sum = 0;
    while (x--)
    {
        sum += H.a[0];
        long long newMax = max((long long)0, H.a[0] - 1);
        H.cut_max();
        H.add(newMax);
    }
    cout << sum;
}