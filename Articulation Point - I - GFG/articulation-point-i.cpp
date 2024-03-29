//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer=0;
    void dfs(int node, int parent, vector<int>&vis,
          vector<int>& mark, int tin[], int low[], vector<int>adj[]){
        tin[node]=low[node]=timer;
        timer++;
        vis[node]=1;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, mark, tin, low, adj);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] and parent != -1){
                    mark[node] = 1;
                }
                child++;
            }else{
                low[node] = min(low[node], tin[it]);
                
            }
        }
        if(child > 1 and parent == -1){
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int>vis(n,0), mark(n, 0);
        int tin[n], low[n];
        
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(0, -1, vis, mark, tin, low, adj);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends