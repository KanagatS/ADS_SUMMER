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
    Node *head;
    Node *cur = head;
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
    Node *j = head;
    int global_max = j->data, local_max = j->data;
    j = j->next;
    while (j != NULL)
    {
        local_max = max(j->data, j->data + local_max);
        if (local_max > global_max)
            global_max = local_max;
        j = j->next;
    }
    cout << global_max;
}