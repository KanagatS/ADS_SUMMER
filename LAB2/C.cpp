#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
    node()
    {
        this->data = 0;
        this->next = NULL;
    }
    node(int x, node *next)
    {
        this->data = x;
        this->next = next;
    }
};

int main()
{
    node *head;
    node *cur;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
        {
            head = new node(a);
            cur = head;
        }
        else if (i % 2 == 0)
        {
            cur->next = new node(a);
            cur = cur->next;
        }
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}