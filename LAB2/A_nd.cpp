#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(NULL) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int findNearest(int k)
    {
        int nearest = INT_MAX;
        int offset = -1;
        int currentIndex = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            int diff = abs(temp->data - k);
            if (diff < nearest)
            {
                nearest = diff;
                offset = currentIndex;
            }
            currentIndex++;
            temp = temp->next;
        }

        return offset;
    }
};

int main()
{
    int n;
    cin >> n;

    LinkedList list;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        list.insert(value);
    }

    int k;
    cin >> k;

    cout << list.findNearest(k);

    return 0;
}
