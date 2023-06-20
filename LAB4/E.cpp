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

Node *search(Node *root, int x)
{
    if (root == NULL)
        return NULL;
    if (root->val == x)
        return root;
    Node *found = search(root->left, x);
    if (found == NULL)
        found = search(root->right, x);
    return found;
}

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
}

int getWidth(Node *root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else
    {
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
    }
}

int getMaxWidth(Node *root)
{
    int max = 0, width;
    int h = getHeight(root);
    for (int i = 1; i <= h; i++)
    {
        width = getWidth(root, i);
        if (width > max)
            max = width;
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    Node *current;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (root == NULL)
        {
            current = new Node(x);
            root = current;
        }
        else
        {
            current = search(root, x);
        }
        Node *tmp = new Node(y);
        if (z == 0)
            current->left = tmp;
        else
            current->right = tmp;
    }
    cout << getMaxWidth(root);
}
