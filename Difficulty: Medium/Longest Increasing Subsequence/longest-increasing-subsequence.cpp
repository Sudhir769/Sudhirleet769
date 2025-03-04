//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& nums){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j=0; j<i; j++){
            if(nums[i] > nums[j]){
                ans = max(ans, 1 + solve(j, nums));
            }
        }
        return dp[i] =  ans;
    }
    int lis(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1, -1);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends