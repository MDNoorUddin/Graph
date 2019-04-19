#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define INF 99999999
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    int n,edge;
    cin>>n>>edge;
    vector<vector<int> > g(n+1);
    int u,v;
    while(edge--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start;
    cin>>start;
    vector<int> distance(n+1);
    fill(distance.begin(),distance.end(),INF);
    vector<bool> vi(n+1);
    distance[start]=0;
    vi[start]=true;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int tp=q.front();
        q.pop();
        for(int i=0;i<g[tp].size();i++)
        {
            int t=g[tp][i];
            distance[t]=min(distance[tp]+1,distance[t]);
            if(!vi[t])
            {
                vi[t]=true;
                q.push(t);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(distance[i]==INF)cout<<-1<<" ";
        else cout<<distance[i]<<" ";
    }
    cout<<endl;
    }
}
