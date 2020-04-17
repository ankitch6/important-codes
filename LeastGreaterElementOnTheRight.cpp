#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	node *left;
	node *right;
}Node;

void BST(Node* &root, int data, Node* &succ)
{
	if (!root)
	{
		root=(Node*)malloc(sizeof(Node));
		root->data=data;
	}

	if(root->data<data)
		BST(root->right, data, succ);
	else if(root->data>data)
	{
		succ=root;
		BST(root->left, data, succ);
	}
}


int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for (int i=0; i<n; i++)
		cin>>arr[i];

	Node* root=NULL;
	for (int i=n-1; i>=0; i--)
	{
		Node* succ=NULL;
		BST(root, arr[i], succ);

		if(succ)
			arr[i]=succ->data;
		else
			arr[i]=-1;
	}

	for (int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	return 0;
}
