//Deletion in a Binary Tree.
//Replace the deleted node with the bottom-most, right-most node
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    node* temp = (node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
};

void Inorder(struct node* root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void DeleteLastNode(struct node* root, int key)
{
    if(!root) return;
    struct node* temp;
    queue<struct node*> q;

    q.push(root);

    while(q.empty() == false)
    {
        temp = q.front();
        q.pop();
        if(temp->data == key)
        {
            free(temp);
            return;
        }
        if(temp->left->data == key)
        {
            free(temp->left);
            temp->left = NULL;
            return;
        }
        if(temp->right->data == key)
        {
            free(temp->right);
            temp->right = NULL;
            return;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

}

void ReplaceNode(struct node* root, int key)
{
    if(!root) return;
    queue<struct node*> q;
    q.push(root);
    struct node *temp, *key_node = NULL;

    while(q.empty() == false)
    {
        temp = q.front();
        q.pop();
        if(temp->data == key)
        {
            key_node = temp;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(key_node == NULL)
        return;
    //temp has the last node
    int x = temp->data;
    temp->data = key_node->data;
    key_node->data = x;

    DeleteLastNode(root, key);
}

int main(void)
{
    struct node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    //In order before deletion
    Inorder(root);
    printf("\n");
    int key = 11;
    ReplaceNode(root, key);
    Inorder(root);
    return 0;
}
