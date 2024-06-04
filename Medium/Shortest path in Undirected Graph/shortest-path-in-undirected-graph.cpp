//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int V,int M, int S){
        vector<int> adjlist[V];
        for(auto it:edges){
            adjlist[it[0]].push_back(it[1]);
            adjlist[it[1]].push_back(it[0]);
        }
        
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>>st; //{dis, node}
        
        st.insert({0, S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            
            int dis = it.first;
            int node = it.second;
            
            for(auto neighbor: adjlist[node]){
                int adjNode = neighbor;
                int edgeW = 1;
                
                if(dis + edgeW < dist[adjNode]){
                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends