#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main(void)
{
    int t;
    cin>>t;
    unordered_map<int,int> umap;

    while(t--)
    {
        int n, ans=0;
        cin>>n;
        umap.clear();
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            umap[a] = b;
        }
        queue<pair<int,int> > q;
        //queue<pair<node, move_count> >
        q.push(make_pair(1,0));

        while(!q.empty())
        {
            int curr_moves = q.front().second;
            int curr_node = q.front().first;
            q.pop();
            if(ans>0 && curr_moves>=ans)
            {
                continue;
            }
            for(int i=1;i<=6;i++)
            {
                int new_node = curr_node + i;
                if(new_node >30)
                    break;
                if(umap.find(new_node)!=umap.end())
                {
                    new_node = umap[new_node];
                }

                if(new_node == 30)
                {
                    if(ans==0)
                        ans = curr_moves+1;
                    else
                        ans = min(ans, curr_moves+1);
                }
                else
                    q.push(make_pair(new_node,curr_moves+1));
            }
        }
        cout<<ans<<endl;
    }
}
