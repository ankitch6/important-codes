//Disjoint Sets
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    int node_rank;
    struct node *parent;

};

map<int, struct node* > m;

struct node* makeset(int data)
{
    struct node *newNode = new struct node;
    newNode->data = data;
    newNode->node_rank = 0;
    newNode->parent = newNode;
    m[data]=newNode;
};

struct node* findSet(struct node* node)
{
    if(node->parent == node)
    {
        return node;
    }
    node->parent = findSet(node->parent);
    return node->parent;
}

void union_set(int data1, int data2)
{
    struct node* node1 = m[data1];
    struct node* node2 = m[data2];

    node1 = findSet(node1);
    node2 = findSet(node2);

    if(node1->data == node2->data)
        return;

    if(node1->node_rank >= node2->node_rank)
    {
        if(node1->node_rank == node2->node_rank)
            node1->node_rank +=1;
        node2->parent = node1;
    }
    else
    {
        node1->parent = node2;
    }
}

int main(void)
{
    int arr[]={1,2,3,4,5,6,7,8,9};

    for(int i=0;i<9;i++)
        makeset(arr[i]);
    int x;
    while(true)
    {
        printf("1. Union\n2. Find Parent\n3. Find Rank\n4. Exit\n");
        scanf("%d", &x);
        if(x==1)
        {
            printf("Enter two numbers: ");
            int a,b;
            scanf("%d%d", &a, &b);
            union_set(a,b);
        }
        else if(x==2)
        {
            printf("Enter the element:");
            int a;
            scanf("%d", &a);
            struct node* parent = findSet(m[a]);
            printf("Parent is: %d\n", parent->data);
        }
        else if(x==3)
        {
            int a;
            printf("Enter element: ");
            scanf("%d", &a);
            struct node* node = m[a];
            printf("Rank is: %d\n", node->node_rank);
        }
        else
            exit(0);
    }
    return 0;
}
