//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapMailNode;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail = details[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail] = i;
                }else{
                    ds.unionSet(i, mapMailNode[mail]);
                }
            }
        }
        vector<string>mergeMail[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.find(it.second);
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string>temp;
            temp.push_back(details[i][0]);
            for(auto it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends