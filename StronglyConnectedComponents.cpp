//This is a function problem to find the Strongly Connected Components
//The count of SCC is returned to the caller function.

void dfs(vector<int> adj[], bool visited[], stack<int>& s, int v)
{
    visited[v] = true;
    for(int i =0; i<adj[v].size(); i++)
    {
        int next = adj[v][i];
        if(visited[next] == false)
        {
            dfs(adj, visited, s, next);
        }
    }
    s.push(v);
}

void dfs_post(vector<int> rev[], bool vis[], int v)
{
    vis[v] = true;
    for(int i=0; i<rev[v].size(); i++)
    {
        int next = rev[v][i];
        if(vis[next] == false)
            dfs_post(rev, vis, rev[v][i]);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    stack<int> s;
    bool visited[V];
    for(int i=0; i<V; i++)
        visited[i] =false;

    for(int i = 0; i<V; i++)
    {
        if(visited[i] == false)
            dfs(adj, visited, s, i);
    }
    //stack is populated
    //Reverse the graph now
    vector<int> rev[V];

    for(int i = 0; i<V; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            int next = adj[i][j];
            rev[next].push_back(i);
        }
    }
    //rev is the new graph
    //now perform DFS
    int count = 0;
    for(int i = 0; i<V; i++)
        visited[i] =false;

    //printf("Size of stack is:%d\n", s.size());

    while(!s.empty()){
        int i = s.top();
        s.pop();
        if(visited[i] == false)
        {
            count++;
            dfs_post(rev, visited, i);
        }
    }

    return count;
}
