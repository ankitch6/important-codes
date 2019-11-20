//binary tree to binary search tree without changing the structure of the binary tree.
//maximum number of nodes in the tree is 20
#include<bits/stdc++.h>
using namespace std;

#define MAXN 20

int arr[MAXN+1];
int k, n;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void print_arr(int arr[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");

}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    arr[n++] = root->data;
    inorder(root->right);

}

void copy_inorder(Node* root)
{
    if(root == NULL)return;

    copy_inorder(root->left);
    root->data = arr[k++];
    copy_inorder(root->right);

}

Node* binaryTreeToBST(Node* root)
{
    if(root == NULL)
        return root;
    n = 0; //the index for the array
    inorder(root);
    printf("Initial Binary Tree(Inorder)\n");
    print_arr(arr, n);
    //now we have the array with all the elements of the Binary Tree
    //The length of the array is n
    //now we sort the array
    sort(arr, arr+n);
    //again perform inorder in the original tree and assign the array elements one by one.
    k = 0;
    copy_inorder(root);
    return root;
}

int main(void)
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);


    root = binaryTreeToBST(root);
    printf("root = %d\nroot->left =%d\nroot->right = %d\nroot->left->left = %d\n",root->data,
                                                                                  root->left->data,
                                                                                  root->right->data,
                                                                                  root->left->left->data);
    n = 0;
    inorder(root);
    print_arr(arr, n);
    return 0;
}
