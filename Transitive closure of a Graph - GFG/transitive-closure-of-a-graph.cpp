//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(vis[i]!=1){
                dfs(i, adj, vis);
            }
        }
    }
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and graph[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            vis[i]=1;
            dfs(i, adj, vis);
            ans.push_back(vis);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends