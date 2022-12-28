#include <iostream>
using namespace std;
/* struct Node{
    int data;
    struct Node* left;
    struct Node *right;
};

struct Node* root=NULL;
struct Node* newnode(int element){
    struct Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=element;
    temp->left=temp->right=NULL;
    return temp;
} */
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *p;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->p = NULL;
    }
};
// Preorder Traversal
void preorder(Node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
// Inorder Traversal
void inorder(Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}
// Postorder Traversal
void postorder(Node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}
// Searching.....
Node *treesearch(Node *root, int k)
{
    if (root == NULL || k == root->data)
    {
        return root;
    }
    if (k < root->data)
    {
        return treesearch(root->left, k);
    }
    else
    {
        return treesearch(root->right, k);
    }
}
Node *iterativets(Node *root, int k)
{
    while (root != NULL && k != root->data)
    {
        if (k < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}
// Minimum and Maximum
Node *minimum(Node *temp)
{
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maximum(Node *temp)
{
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
// Successor and Predecessor
// Successor is next node in inorder traversal
Node *successor(Node *temp)
{
    if (temp->right != NULL)
    {
        return minimum(temp->right);
    }
    Node *y = temp->p;
    while (y != NULL && temp == y->right)
    {
        temp = y;
        y = y->p;
    }
    return y;
}
// Successor without parent
Node *successorwp(Node *y, Node *temp)
{
    if (temp->right != NULL)
    {
        return minimum(temp->right);
    }
    Node *succ = NULL;
    while (true)
    {
        if (temp->data < y->data)
        {
            succ = y;
            y = y->left;
        }
        else if (temp->data > y->data)
        {
            y = y->right;
        }
        else
        {
            break;
        }
    }
    return succ;
}
// Insertion :D
Node *insert(Node *root, Node *z)
{
    if (root == NULL)
    {
        return z;
    }
    if (z->data < root->data)
    {
        root->left = insert(root->left, z);
        root->left->p = root;
    }
    else if (z->data > root->data)
    {
        root->right = insert(root->right, z);
        root->right->p = root;
    }
    return root;
}
// Deletion :D
void deletion(Node *root, int d)
{
    Node *z = treesearch(root, d);
    // Check number of children
    // No children
    if (z->right == NULL && z->left == NULL)
    {
        if (z->p->data < z->data)
        {
            z->p->right = NULL;
        }
        else if (z->p->data > z->data)
        {
            z->p->left = NULL;
        }
        z->p = NULL;
    }
    // One Children
    if (z->right != NULL && z->left == NULL)
    {
        if (z->p->data < z->data)
        {
            z->p->right = z->right;
        }
        else if (z->p->data > z->data)
        {
            z->p->left = z->right;
        }
        z->p = NULL;
        z->right = NULL;
    }
    if (z->right == NULL && z->left != NULL)
    {
        if (z->p->data < z->data)
        {
            z->p->right = z->left;
        }
        else if (z->p->data > z->data)
        {
            z->p->left = z->left;
        }
        z->p = NULL;
        z->left = NULL;
    }
    // Two children
    if (z->right != NULL && z->left != NULL)
    {
        Node *q = new Node(successor(z->right)->data);
        deletion(root, q->data);
        if (z->p->data < z->data)
        {
            z->p->right = q;
            q->p = z->p;
            q->left = z->left;
            q->right = z->right;
        }
        else if (z->p->data > z->data)
        {
            z->p->left = q;
            q->p = z->p;
            q->left = z->left;
            q->right = z->right;
        }
        z->p = NULL;
        z->right = NULL;
        z->left = NULL;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    Node *root = new Node(15);
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        Node *k = new Node(arr[i]);
        insert(root, k);
    }
    cout << "Preorder" << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(root);
    cout << endl;
    deletion(root, 4);
    cout << "Inorder after deleting 4" << endl;
    inorder(root);
    deletion(root, 7);
    cout << "Inorder after deleting 7" << endl;
    inorder(root);
    deletion(root, 15);
    cout << "Inorder after deleting 15" << endl;
    inorder(root);
}