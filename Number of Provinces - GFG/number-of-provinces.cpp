//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    public:
    vector<int>par;
    
    DisjointSet(int V){
        par.resize(V+1);
        for(int i=0;i<=V;i++){
            par[i]=i;
        }
    }
    int find(int x){
        if(x==par[x]) return x;
        
        return par[x] = find(par[x]);
    }
    
    void unionSet(int u, int v){
        par[find(u)] = find(v);
    }
};

class Solution {
    
    public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        DisjointSet ds(V);
        
        for(int i=0; i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1) ds.unionSet(i,j);
            }
        }
        int cnt=0;
        
        for(int i=0; i<V; i++){
            if(ds.par[i]==i)cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends