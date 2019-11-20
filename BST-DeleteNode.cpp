//Delete a Node from a Binary Tree
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void Inorder(struct Node* root)
{
    if(root==NULL) return;

    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

Node* insert(Node* root, int key)
{
    if(root == NULL)
        return new Node(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

Node* deleteNode(Node* root, int key)
{
    if(root == NULL) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        //this is the node to be deleted
        if(root->right == NULL && root->left == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->right && root->left)
        {
            //find the inorder successor of the root
            Node* temp = root->right;

            while(temp->left)
                temp=temp->left;
            root->data = temp->data;
            //now delete the temp node
            root->right = deleteNode(root->right, temp->data);
        }
        else if(root->left)
        {
            //only left child exists
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else if(root->right)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
    }
}
int main(void)
{
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder before deletion.\n");
    Inorder(root);
    printf("\n");

    printf("Deleting Node 50!\n");
    root = deleteNode(root, 50);
    Inorder(root);
    return 0;
}
