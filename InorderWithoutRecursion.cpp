//INORDER WITHOUT RECURSION
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

node* newnode(int data)
{
    struct node* temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void Inorder(node* root)
{
    stack<node*> s;
    node* current=root;

    while(current != NULL || s.empty() == false)
    {
        while(current != NULL)
        {
            s.push(current);
            current = current->left;
        }
            current = s.top();
            s.pop();
            printf("%d  ", current->data);
            current = current->right;
    }
}
int main(void)
{
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    Inorder(root);
    return 0;
}
