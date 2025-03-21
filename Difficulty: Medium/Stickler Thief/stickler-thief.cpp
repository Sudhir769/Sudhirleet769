//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int dp[100001];
    int solve(vector<int>& arr, int ind, int n){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int take = solve(arr, ind+2, n) + arr[ind];
        int not_take = solve(arr, ind+1, n);
        
        return dp[ind] = max(take, not_take);
    }
    
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, n);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends