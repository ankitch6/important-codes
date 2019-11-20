//Topological Sorting
#include<bits/stdc++.h>
using namespace std;

int V;

void topologicalSort(vector<int> adj[])
{
    int in_degree[V];
    memset(in_degree, 0, sizeof(in_degree));
    for(int i = 0; i<V; i++)
    {
        for(int j = 0; j< adj[i].size(); j++)
        {
            int v = adj[i][j];
            in_degree[v] += 1;
        }
    }
    int ans[V], k = 0;
    queue<int> q;
    for(int i = 0; i< V; i++)
    {
        if(in_degree[i] == 0)
            q.push(i);
    }
    while(q.empty() == false)
    {
        int x = q.front();
        q.pop();
        ans[k++] = x;
        for(int i = 0; i< adj[x].size(); i++)
        {
            int index = adj[x][i];
            in_degree[index] -= 1;
            if(in_degree[index] == 0)
                q.push(index);
        }
    }
    for(int i=0; i<V;i++)
        printf("%d ", ans[i]);
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
int main(void)
{
    V = 6;
    vector<int> adj[V];
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 5, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 1);

    topologicalSort(adj);
    return 0;
}
/*  Recursive Solution using DFS!

stack<int> S;
void topo_util(vector<int> adj[], bool visited[], int v)
{
    visited[v] = true;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int index = adj[v][i];
        if(!visited[index])
            topo_util(adj, visited, index);
    }
    S.push(v);
}
int* topoSort(int V, vector<int> adj[])
{
    //vertices are numbered from 0 to V-1
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false)
            topo_util(adj, visited, i);
    }
    int k = 0;
    int *arr =(int*)malloc(sizeof(int)*V);
    while(!S.empty())
    {
        arr[k++] = S.top();
        S.pop();
    }
    return arr;
}
*/
