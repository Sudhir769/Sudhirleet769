//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n,
        vector<int> &query, int q) {
        
        // vector<int>ans;
        // int k=0;
        // while(k < q){
        //     int x = query[k];
            
        //     int el = a[x];
        //     int cnt=0;
        //     for(int i=0; i<n; i++){
        //         if(b[i] <= el){
        //             cnt++;
        //         }
        //     }
        //     ans.push_back(cnt);
        //     k++;
        // }
        // return ans;
        
        int maxEle = *max_element(a.begin(), a.end());
        vector<int> freq(maxEle+1);

        for(int i = 0;i < n; i++) {
            if(b[i] <= maxEle)
                freq[b[i]]++;
        }
        
        for(int i = 1;i <= maxEle; i++)
            freq[i] += freq[i-1];

        vector<int> ans;
        for(auto x : query)
            ans.push_back(freq[a[x]]);

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
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends