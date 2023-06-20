#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(1001);
    Node *head;
    Node *cur;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
        {
            head = new Node(a);
            cur = head;
        }
        else
        {
            cur->next = new Node(a);
            cur = cur->next;
        }
    }
    cur = head;
    while (n--)
    {
        int a = cur->data;
        v[a]++;
        cur = cur->next;
    }
    int max_freq = *max_element(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == max_freq)
        {
            cout << i << " ";
        }
    }
}