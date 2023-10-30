//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	vector<int>dp;
	int solve(int ind, int *arr){
	    if(ind==0) return arr[ind];
	    if(ind<0) return 0;
	    
	    if(dp[ind]!=-1) return dp[ind];
	    
	    int take = arr[ind] + solve(ind-2, arr);
	    int not_take = 0 + solve(ind-1, arr);
	    
	    return dp[ind] = max(take, not_take);  
	}
	int findMaxSum(int *arr, int n) {
	    dp.resize(n, -1);
	   // return solve(n-1, arr);
	   int prev2 = 0;
	   int prev1 = arr[0];
	   
	   for(int i=1; i<n;i++){
	       int take = arr[i] + prev2;
	       int not_take =  0 + prev1;
	       
	       int curr = max(take, not_take);
	       prev2 = prev1;
	       prev1 = curr;
	   }
	   return prev1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends