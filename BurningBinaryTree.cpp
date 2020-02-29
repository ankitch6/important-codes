//https://www.geeksforgeeks.org/burn-the-binary-tree-starting-from-the-target-node/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
queue<node*> q;

node* newNode(int data)
{
    struct node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int burnTreeUtil(node* root, int target)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->data == target)
    {
        printf("%d\n", target);
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        return 1;
    }
    int a = burnTreeUtil(root->left, target);

    if(a==1)
    {
        int qsize = q.size();
        while(qsize--)
        {
            node* node = q.front();
            printf("%d  ", node->data);

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            q.pop();
        }
        printf("%d\n", root->data);
        //push the right subtree in the queue
        if(root->right)
            q.push(root->right);

        return 1;
    }
    int b = burnTreeUtil(root->right, target);

    if(b==1)
    {
        int qsize = q.size();
        while(qsize--)
        {
            node* temp = q.front();
            q.pop();
            printf("%d  ", temp->data);

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        printf("%d\n", root->data);
        if(root->left)
            q.push(root->left);

        return 1;
    }
}
void burnTree(node* root, int target)
{
    burnTreeUtil(root, target);

    int qsize = q.size();
    while(qsize--)
    {
        node* temp = q.front();
        printf("%d  ", temp->data);
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        if(qsize == 0)
        {
            qsize = q.size();
            printf("\n");
        }
    }
}
int main(void)
{
    struct node* root = NULL;

    root = newNode(12);
    root->left = newNode(13);
    root->right = newNode(10);
    root->right->left = newNode(14);
    root->right->right = newNode(15);
    root->right->left->left = newNode(21);
    root->right->left->right = newNode(24);
    root->right->right->left = newNode(22);
    root->right->right->right = newNode(23);
    root->right->right->right->left = newNode(55);
    root->right->right->right->right = newNode(45);
    root->left->right = newNode(99);
    root->left->right->right = newNode(69);

    int targetNode = 14;
    burnTree(root, targetNode);
    return 0;
}
