//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   void DFS1(int &tim,vector<int>adj[],int V,vector<bool>&vis,vector<int>&disc,vector<int>&low,
            int parent,int s,vector<bool>&res){
       vis[s]=true;
       disc[s]=low[s]=tim++;
       int child=0;
       for(int u: adj[s]){
           if(u==parent){
               continue;
           }
           else if(vis[u]==false){
              DFS1(tim,adj,V,vis,disc,low,s,u,res);
              if(parent==-1){
                  child++;
              }
              low[s]=min(low[s],low[u]);
              if(parent!=-1 && low[u]>=disc[s]){
                  res[s]=true;
              }
           }
           else {
               low[s]=min(low[s],disc[u]);
           }
       }
        if(parent==-1 && child>1){
            res[s]=true;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
         int tim=0;
       vector<bool>vis(V,false);
       vector<int>disc(V,0);
       vector<int>low(V,0);
       vector<bool>res(V,false);
       vector<int>ans;
       for(int i=0;i<V;i++){
           if(!vis[i]){
           DFS1(tim,adj,V,vis,disc,low,-1,i,res);}
       }
       for(int i=0;i<V;i++){
           if(res[i]==true){
               ans.push_back(i);
           }
       }
       if(ans.size()==0){
           ans.push_back(-1);
       }
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