//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n = 0;
    vector<vector<int>> dp;
    int solve(int i, vector<int> &coins, int sum){
        if(i >= n){
            return sum == 0;
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int take = 0;
        if(sum >= coins[i]){
            take = max(solve(i, coins, sum - coins[i]), solve(i+1, coins, sum - coins[i]));
        }
        int notTake = solve(i+1, coins, sum);
        
        return dp[i][sum] = (take + notTake);
    }
    
    int count(vector<int>& coins, int sum) {
        n = coins.size();
        
        dp.resize(n+1, vector<int> (sum+1, -1));
        return solve(0, coins, sum);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends