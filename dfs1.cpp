#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes,edges;
    while(cin>>nodes>>edges){
        vector<int> Graph[nodes];
        int u,v;
        while(edges--)
        {
            cin>>u>>v;
            Graph[u].push_back(v);
            //Graph[v].push_back(u);
        }
        int Visit[nodes];
        memset(Visit,-1,sizeof(Visit));
        stack<int> st;
        int start;
        cin>>start;
        st.push(start);
        Visit[start]=1;
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            cout<<top<<"-->";
            for(vector<int>::iterator i=Graph[top].begin();i!=Graph[top].end();i++)
            {
                if(Visit[*i]==-1) {
                    st.push(*i);
                    Visit[*i]=1;
                }
            }
        }
        cout<<"-->end\n";
    }
    return 0;
}
