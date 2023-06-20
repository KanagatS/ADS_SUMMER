#include <iostream>
#include <algorithm>

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
            cnt++;
            cnt = count(current->left, cnt);
            cnt = count(current->right, cnt);
        }
        return cnt;
    }

    int getHeight(Node *current)
    {
        if (current->right == NULL && current->left == NULL)
            return 0;
        int left = 0, right = 0;
        if (current->left != NULL)
            left = getHeight(current->left);
        if (current->right != NULL)
            right = getHeight(current->right);

        return (max(left, right) + 1);
    }

    void levelSum(Node *current, int level, int sum[])
    {
        if (current == NULL)
            return;
        sum[level] += current->val;
        levelSum(current->right, level + 1, sum);
        levelSum(current->left, level + 1, sum);
    }

    int levelSum2(Node *current, int level, int h, int &sum)
    {
        if (level == h || current == NULL)
            return 0;
        sum += current->val - level;
        levelSum2(current->left, level + 1, h, sum);
        levelSum2(current->right, level + 1, h, sum);
        return sum;
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
    int levels = B->getHeight(B->root) + 1;
    int sum = 0;
    cout << B->levelSum2(B->root, 0, levels, sum);
}