#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
// 10 8 21 7 27 5 4 3 -1
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *minval(Node *root)
{
    if (!root)
        return root;

    Node *temp = root;
    while (temp->left)
        temp = temp->left;

    return temp;
}
Node *maxval(Node *root)
{
    if (!root)
        return root;

    Node *temp = root;
    while (temp->right)
        temp = temp->right;

    return temp;
}

Node *deleteFromBST(Node *root, int d)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == d)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child

        // left
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            // fetch the minimum value from the right
            // or fetch the maximum value from the left

            Node *temp = minval(root->right); // fetching min val from right
            root->data = temp->data;          // then replace
            root->right = deleteFromBST(root->left, d);
            delete root;
        }
    }
    else if (d > root->data)
    {
        root->right = deleteFromBST(root->right, d);
        return root;
    }
    else
    {
        root->left = deleteFromBST(root->left, d);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    cout << "please enter data to create BST" << endl;
    takeInput(root);

    cout << "The BST is" << endl;
    levelOrderTraversal(root);

    cout << "inorder Traversal" << endl;
    inorder(root);
    cout << endl;
    cout << "preorder Traversal" << endl;
    preorder(root);
    cout << endl;
    cout << "postorder Traversal" << endl;
    postorder(root);

    cout << endl
         << endl
         << "delete root" << endl;
    deleteFromBST(root, 5);
    levelOrderTraversal(root);
    cout << endl
         << "after deletion" << endl;
    inorder(root);
}
// 10 8 21 7 27 5 4 3 -1