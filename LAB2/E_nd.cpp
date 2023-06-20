#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string data;
    Node *next;
};

void removeDuplicates(Node *head)
{
    Node *cur = head;
    Node *rem = head;
    while (cur != NULL)
    {
        if (cur->data == rem->data)
        {
            rem->next = cur->next;
            Node *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        else
        {
            rem->next = cur;
            rem = rem->next;
            cur = cur->next;
        }
        // cur = cur->next;
    }
}

int getCount(Node *head)
{
    int count = 0;
    Node *cur = head;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

void push(Node **head_ref, string new_data)
{

    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "\n";
        node = node->next;
    }
}

int main()
{
    int n;
    string s;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        push(&head, s);
    }

    removeDuplicates(head);
    cout << "All in all: " << getCount(head);

    cout << "\nStudents:\n";
    printList(head);

    return 0;
}