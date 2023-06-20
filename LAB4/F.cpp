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

    Bst()
    {
        this->root = NULL;
    }

    Node *add(Node *current, int x)
    {
        if (current == NULL)
        {
            current = new Node(x);
        }
        else if (current->val > x)
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
        else if (current->val > x)
            return search(current->left, x);
        else if (current->val < x)
            return search(current->right, x);
    }

    void print(Node *current)
    {
        if (current != NULL)
        {
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }

    int count(Node *current, int cnt)
    {
        if (current != NULL)
        {
            if (current->right != NULL && current->left != NULL)
                cnt++;
            cnt = count(current->left, cnt);
            cnt = count(current->right, cnt);
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    Bst *B = new Bst();
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (B->root == NULL)
            B->root = B->add(B->root, x);
        else
            B->add(B->root, x);
    }
    cout << B->count(B->root, 0);
}