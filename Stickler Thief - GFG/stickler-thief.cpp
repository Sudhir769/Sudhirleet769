//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    vector<int>dp;
    int solve(int arr[], int ind, int n){
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
    
    int FindMaxSum(int arr[], int n)
    {
        dp.resize(n, -1);
        
        // return solve(arr, 0, n);
        
        int prev1=arr[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int take = arr[i] + prev2;
            int not_take = 0 + prev1;
            
            int curr = max(take, not_take);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends