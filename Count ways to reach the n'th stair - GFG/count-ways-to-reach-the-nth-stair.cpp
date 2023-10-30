//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = 1e9+7;
    // vector<int>dp;
    
    // int solve(int n){
    //     if(n==0 or n==1) return 1;
        
    //     if(dp[n]!=-1) return dp[n];
        
    //     return dp[n] =  (countWays(n-1))%mod + (countWays(n-2))%mod; 
        
    // }
    int countWays(int n)
    {
        // dp.resize(n+1, -1);
        // return solve(n);
        
        int prev1=1;
        int prev2=1;
        
        for(int i=2;i<=n;i++){
            int curr = (prev1 + prev2)%mod;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends