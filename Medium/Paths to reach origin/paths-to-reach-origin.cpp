//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int mod = 1e9+7;
    vector<vector<int>>dp;
    int solve(int i, int j){
        if(i==0 and j==0) return 1;
        if(i<0 or j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = (solve(i-1, j) + solve(i, j-1))%mod;
    }
    
    int ways(int x, int y)
    {
        dp.resize(x+1, vector<int>(y+1, -1));
        return solve(x, y);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends