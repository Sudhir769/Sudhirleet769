//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>>dp;
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        dp.resize(n+1, vector<int>(sum+1, 0));
        for(int i=0;i<n;i++) dp[i][0] = 1;
        if(arr[0] <= sum) dp[0][arr[0]] = 1;
        
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target<=sum; target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
                dp[ind][target] = take | notTake;
            }
        }
        return dp[n-1][sum];
        
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends