#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->val = x;
        this->left = this->right = NULL;
    }
};

struct Bst
{
    Node *root;

    Node *add(Node *current, int x)
    {
        if (current == NULL)
        {
            current = new Node(x);
        }
        else if (x < current->val)
        {
            if (current->left == NULL)
                current->left = add(current->left, x);
            else
                add(current->left, x);
        }
        else
        {
            if (current->right == NULL)
                current->right = add(current->right, x);
            else
                add(current->right, x);
        }
        return current;
    }

    Node *search(Node *current, int x)
    {
        if (current == NULL)
            return NULL;
        if (current->val == x)
            return current;
        else if (x < current->val)
            return search(current->left, x);
        else
            return search(current->right, x);
    }

    void print(Node *current)
    {
        if (current != NULL)
        {
            cout << current->val << " ";
            print(current->left);
            print(current->right);
        }
    }

    Bst()
    {
        this->root = NULL;
    }
};

int main()
{
    int n;
    cin >> n;
    Bst *B = new Bst();
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (B->root == NULL)
            B->root = B->add(B->root, a);
        else
            B->add(B->root, a);
    }
    int k;
    cin >> k;
    Node *subnode = B->search(B->root, k);
    B->print(subnode);
}