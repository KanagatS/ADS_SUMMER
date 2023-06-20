#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
    Node(int x, Node *next)
    {
        this->data = x;
        this->next = next;
    }
};

int main()
{
    int n;
    cin >> n;
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
    int newdata;
    cin >> newdata;
    int pos;
    cin >> pos;
    int cnt = 0;
    cur = head;
    while (cnt < pos - 1)
    {
        cur = cur->next;
        cnt++;
    }
    if (pos == 0)
    {
        head = new Node(newdata, cur);
    }
    else
    {
        Node *newnode = new Node(newdata, cur->next);
        cur->next = newnode;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}