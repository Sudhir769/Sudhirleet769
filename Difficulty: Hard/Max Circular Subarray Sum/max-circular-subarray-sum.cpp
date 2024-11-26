//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int SUM = 0;
    int kadaneMin(vector<int>& arr){
        int minSum = INT_MAX;
        int currSum = 0;
        
        for(auto num:arr){
            currSum += num;
            minSum = min(minSum, currSum);
            
            if(currSum > 0) currSum = 0;
            
            SUM += num;
        }
        return minSum;
    }
    int kadaneMax(vector<int>& arr){
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(auto num:arr){
            currSum += num;
            maxSum = max(maxSum, currSum);
            
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
    
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        int maxSum = kadaneMax(arr);
        int minSum = kadaneMin(arr);
        
        maxSum = max(maxSum, SUM - minSum);
        
        return maxSum;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends