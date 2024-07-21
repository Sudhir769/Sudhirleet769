//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int numofzero=0;
        int mod=1e9+7;
        long long int small=INT_MIN;
        long long int res=1;
        for(auto i : arr){
            if(i==0) numofzero++;
            else{
                if(i<0)
                small=max(small,(long long int)i);
                res=(res*i)%mod;
            }
        }
        
        if(numofzero==arr.size()) return 0;
        if(arr.size()==1 && small!=INT_MIN) return small;
        if(arr.size()==(numofzero+1) && small!=INT_MIN){
            return 0;
        }
        if(res<0){
            res=res/small;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends