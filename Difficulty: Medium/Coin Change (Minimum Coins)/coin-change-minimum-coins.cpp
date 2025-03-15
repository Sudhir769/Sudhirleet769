//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int i, vector<int>& coins, int sum){
        if(sum == 0){
            return 0;
        }
        if(i < 0) return INT_MAX;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int take = INT_MAX;
        if(sum >= coins[i]){
            int temp = solve(i, coins, sum-coins[i]);
            if(temp != INT_MAX){
                take = 1 + temp;
            }
        }
        int notTake = solve(i-1, coins, sum);
        
        return dp[i][sum] = min(take, notTake);
    }
    
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        
        dp.resize(n+1, vector<int>(sum+1, -1));
        int ans = solve(n-1, coins, sum);
        if(ans != INT_MAX){
            return ans;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends