//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    vector<vector<long long>>dp;
    long long solve(int start, int end, int arr[]){
        if(start > end) return 0;
        if(start == end) return arr[start];
        if(dp[start][end] != -1) return dp[start][end];
        
        long long x = arr[start] + min(solve(start+2, end, arr), solve(start+1, end-1, arr));
        long long y = arr[end] + min(solve(start, end-2, arr), solve(start+1, end-1, arr));
        
        return dp[start][end] = max(x, y);
    }
    long long maximumAmount(int n, int arr[]){
        dp.resize(n+1, vector<long long>(n+1, -1));
        return solve(0, n-1, arr);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends