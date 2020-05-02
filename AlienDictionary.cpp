#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main(void)
{
   int t,n,k;
   cin>>t;
   while(t--)
   {
       cin>>n>>k;
       vector<string> dict;
       bool graph[k][k];
       for(int i=0; i<n; i++)
       {
           string t;
           cin>>t;
           dict.push_back(t);
       }
       //initialize the graph
       for(int i=0; i<k; i++)
          for(int j=0; j<k; j++)
             graph[i][j] = false;
       //to store the in degree of each node
       int in_degree[k];

       for(int i=0; i<k; i++)
          in_degree[i] = 0;

       //populate the graph using the dictionary
       int curr = 1, prev = 0;
       while(curr<n)
       {
            int prev_it = 0;
            int curr_it = 0;
            while(dict[curr][curr_it] == dict[prev][prev_it])
            {
                curr_it++;
                prev_it++;
            }
            int u = dict[prev][prev_it] - 'a';
            int v = dict[curr][curr_it] - 'a';
            graph[u][v] = true;

            curr++;
            prev++;
       }
       //populate the in_degree array
       for(int i=0; i<k; i++)
       {
           for(int j=0; j<k; j++)
           {
               if(graph[i][j])
               {
                   in_degree[j]++;
               }
           }
       }
       queue<int> q;
       for(int i=0; i<k; i++)
       {
           if(in_degree[i] == 0)
              q.push(i);
       }
       string res = "";
       while(!q.empty())
       {
           int top = q.front();
           q.pop();
           char t = 'a'+ top;
           res.push_back(t);

           for(int i=0; i<k; i++)
           {
               if(graph[top][i] == true)
               {
                    in_degree[i]--;

                    if(in_degree[i] == 0)
                      q.push(i);
               }
           }
       }
       cout<<res<<endl;
   }
   return 0;
}
