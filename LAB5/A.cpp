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
            min = l;
        if (r < this->size && a[min] > a[r])
            min = r;
        if (i != min)
        {
            swap(a[i], a[min]);
            heapDown(min);
        }
    }

    void cut_min()
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
    long long n;
    cin >> n;
    Heap H(n);
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        H.add(x);
    }
    long long sum = 0;
    while (H.size != 1)
    {
        long long local = 0;
        local += H.a[0];
        H.cut_min();
        local += H.a[0];
        H.cut_min();
        H.add(local);
        sum += local;
    }
    cout << sum;
}