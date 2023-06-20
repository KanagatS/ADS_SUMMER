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
        long long min = i;
        if (l < this->size && a[min] < a[l])
        {
            min = l;
        }
        if (r < this->size && a[min] < a[r])
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

    void cut_max()
    {
        a[0] = a[size - 1];
        size = max((long long)0, size - 1);
        heapDown(0);
    }

    int findMin()
    {
        int minEl = a[size / 2];
        int res = size / 2;
        for (int i = 1 + size / 2; i < size; i++)
        {
            if (a[i] < a[res])
            {
                res = i;
            }
        }
        return res;
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
    int q, k;
    cin >> q >> k;
    Heap H(k);
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            long long x;
            cin >> x;
            if (H.size < k)
            {
                H.add(x);
            }
            else
            {
                int min = H.findMin();
                if (H.a[min] < x)
                {
                    H.a[min] = x;
                    H.heapUp(min);
                }
            }
        }
        if (s == "print")
        {
            long long sum = 0;
            for (int i = 0; i < H.size; i++)
            {
                sum += H.a[i];
            }
            cout << sum << "\n";
        }
    }
}