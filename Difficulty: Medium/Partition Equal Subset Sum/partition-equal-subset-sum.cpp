//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(int i, vector<int> &arr, int target){
        if(i < 0) return false;
        if(target == 0) return true;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        bool notTake = solve(i-1, arr, target);
        bool take = false;
        if(target >= arr[i]){
            take = solve(i-1, arr, target - arr[i]);
        }
        
        return dp[i][target] = notTake | take;
    }
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if(totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        
        dp.resize(n, vector<int>(target+1, -1));
        return solve(n-1, arr, target);
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends