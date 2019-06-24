#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

#define edge pair<int, int>

class Graph
{
private:
    vector<pair<int, edge> > G;//graph
    vector<pair<int, edge> > T;//MST
    int V;
    int *parent;//parent points to the root integer

public:
    Graph(int V);
    void union_set(int u, int v);
    int find_set(int i);
    void kruskal();
    void AddWeightedEdge(int w, int u, int v);
    void print();
};

Graph::Graph(int V)
{
    //constructor of the class Graph
    /*allocate a space for V integers
      and initialize as their own parents*/
    parent = new int[V];

    for(int i=0; i< V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u,v)));
}
int Graph::find_set(int i)
{
    if(parent[i] == i)
        return i;
    else
        parent[i] = find_set(parent[i]);

    return parent[i];
}
void Graph::union_set(int u, int v)
{
    if(parent[u] == parent[v])
        return;
    parent[u]=parent[v];
}
void Graph::kruskal()
{
    sort(G.begin(), G.end());
    int u, v;
    int len=G.size();
    for(int i=0;i<len;i++)
    {
        u=G[i].second.first;
        v=G[i].second.second;
        if(find_set(u) == find_set(v))
            continue;
        else
        {
            union_set(find_set(u), find_set(v));
            T.push_back(G[i]);
        }
    }
}
void Graph::print()
{
    int len=T.size();
    cout<<"Edge : Weight"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<T[i].second.first<<" - "<<T[i].second.second<<" : " <<T[i].first<<endl;
    }
}
int main(void)
{
    Graph g(6);//object of the class with the parameter to the constructor
    g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(1, 0, 4);
    g.AddWeightedEdge(2, 0, 4);
    g.AddWeightedEdge(2, 1, 2);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 2, 3);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(4, 2, 4);
    g.AddWeightedEdge(4, 3, 3);
    g.AddWeightedEdge(5, 2, 2);
    g.AddWeightedEdge(5, 4, 3);
    g.kruskal();
    g.print();
    return 0;
}
