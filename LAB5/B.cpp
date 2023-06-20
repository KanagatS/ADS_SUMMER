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

    void add(long long x)
    {
        a[size] = x;
        size++;
        heapUp(size - 1);
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
            max = l;
        if (r < this->size && a[max] < a[r])
            max = r;
        if (i != max)
        {
            swap(a[i], a[max]);
            heapDown(max);
        }
    }

    void cut_max()
    {
        a[0] = a[size - 1];
        size = max((long long)0, size - 1);
        heapDown(0);
    }

    void print()
    {
        for (long long i = 0; i < size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    Heap(long long x)
    {
        this->a = new long long[x];
        this->capacity = x;
        this->size = 0;
    }
};

int main()
{
    int n;
    cin >> n;
    Heap H(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        H.add(x);
    }
    while (H.size > 1)
    {
        int y = H.a[0];
        H.cut_max();
        int x = H.a[0];
        H.cut_max();
        if (x < y)
        {
            y -= x;
            H.add(y);
        }
        else if (x == y)
        {
            continue;
        }
    }
    if (H.size > 0)
        cout << H.a[0];
    else
        cout << 0;
}