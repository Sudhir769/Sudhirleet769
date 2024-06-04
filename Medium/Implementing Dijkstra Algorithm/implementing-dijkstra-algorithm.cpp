//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<pair<int, int>> adjlist[V];
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                adjlist[i].push_back({it[0], it[1]});
            }
        }
        
        vector<int> dist(V, 1e9);
        set<pair<int, int>>st; //{dis, node}
        
        st.insert({0, S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            
            int dis = it.first;
            int node = it.second;
            
            for(auto neighbor: adjlist[node]){
                int adjNode = neighbor.first;
                int edgeW = neighbor.second;
                
                if(dis + edgeW < dist[adjNode]){
                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends