
/** Node Starts from 0 not 1.
    This program will traverse all the nodes from a starting point*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node;
    while(cin>>node)
    {
        int edge;
        cin>>edge;
        vector<int> Graph[node];
        int Visit[node];
        memset(Visit,-1,sizeof(Visit));
        int u,v;
        while(edge--)
        {
            cin>>u>>v;
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        queue<int> bi;
        int startNode;
        cin>>startNode;
        bi.push(startNode);Visit[startNode]=1;
        while(!bi.empty())
        {
            int f=bi.front();
            cout<<f<<"-->";
            bi.pop();
            for(vector<int>::iterator it=Graph[f].begin();it!=Graph[f].end();it++)
            {
                if(Visit[*it]==-1)
                {
                    Visit[*it]=1;
                    bi.push(*it);
                }
            }
        }
        cout<<"end\n";
    }
    return 0;
}
