#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main(void)
{
    int N;
    scanf("%d", &N);
    //nodes are numbered from 0 to N-1
    int arr[N][N];
    for(int i =0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    //we have to find the shortest path from a given vertex to another
    //dist: 0 node: 0
    int parent[N];
    int distance[N];

    for(int i = 0; i<N; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    pq.push(make_pair(0, 0));
    distance[0] = 0;
    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();

        for(int i = 0; i<N; i++)
        {
            if(arr[node][i] > 0)
            {
                //check if the distance from this node is less than the previous distance stored
                //this is an edge, push this edge to the priority queue
                if(distance[node] + arr[node][i] < distance[i]){
                    distance[i] = distance[node] + arr[node][i];
                    printf("Distance of %d is set to %d\n", i, distance[i]);
                    parent[i]=node;
                    pq.push(make_pair(arr[node][i], i));
                }
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        printf("Shortest path from 0th node to %d node is = %d\n", i, distance[i]);
    }
    return 0;
}
