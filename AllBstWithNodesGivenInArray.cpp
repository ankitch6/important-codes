#include bitsstdc++.h
using namespace std;

typedef struct Node
{
	int data;
	Node left;
	Node right;
}Node;

vectorNode makeTrees (int start, int end)
{
	vectorNode list;
	if(startend)
	{
		list.push_back(NULL);
		return list;
	}

	for (int k=start; k=end; k++)
	{
		vectorNode leftSub = makeTrees(start, k-1);
		vectorNode rightSub = makeTrees(k+1, end);

		for (int i=0; ileftSub.size(); i++)
		{
			Node left=leftSub[i];
			for (int j=0; jrightSub.size(); j++)
			{
				Node right=rightSub[j];
				Node node=(Node)malloc(sizeof(Node));
				node-data=k;
				node-left=left;
				node-right=right;
				list.push_back(node);
			}
		}
	}
	return list;
}

void preorder (Node root)
{
	if (!root)
		return;
	coutroot-data ;
	preorder(root-left);
	preorder(root-right);
}

int main() {
	 your code goes here
	int t;
	cint;
	while(t--)
	{
		int n;
		cinn;

		vectorNode trees = makeTrees(1,n);

		for (int i=0; itrees.size(); i++)
		{
			preorder(trees[i]);
			coutendl;
		}
	}
	return 0;
}
