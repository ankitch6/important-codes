//detect a cycle in a directed graph
#include<bits/stdc++.h>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

bool DFSUtil(int v, int color[], vector<int> adj[])
{
    color[v] = GRAY;

    for(int i = 0; i < adj[v].size(); i++)
    {
        int next = adj[v][i];
        if(color[next] == GRAY)
        {
            return true;
        }
        if(color[next] == WHITE && DFSUtil(next, color, adj))
        {
            return true;
        }
    }
    color[v] = BLACK;
    return false;
}
int main(void)
{
    int V = 5;
    vector<int> adj[V];

    int *color = new int[V];
    for(int i = 0; i < V; i++)
        color[i]= WHITE;

    for(int i=0; i<V;i++)
    {
        if(color[i] == WHITE)
        {
            bool flag = DFSUtil(i, color, adj);
            if(flag == true)
                printf("Cycle is present~");
        }
    }
    return 0;
}
