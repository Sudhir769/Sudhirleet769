//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(int i, vector<int>& arr, int sum){
        if(i < 0) return sum == 0;
        if(sum == 0) return true;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = false;
        if(sum >= arr[i]){
            take = solve(i-1, arr, sum - arr[i]);
        }
        
        bool notTake = solve(i-1, arr, sum);
        
        return dp[i][sum] = take | notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        dp.resize(n, vector<int>(sum+1, -1));
        return solve(n-1, arr, sum);
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