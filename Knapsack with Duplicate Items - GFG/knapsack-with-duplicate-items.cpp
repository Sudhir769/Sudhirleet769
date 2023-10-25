//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int ind, int currVal,  int currWt,  int N, int W, int val[], int wt[], vector<vector<int>>&dp){
        if(ind==N) return 0;
        // if(currWt>=W) return 0;
        
        if(dp[ind][currWt]!=-1) return dp[ind][currWt];
        
        int not_take = solve(ind+1, currVal, currWt, N, W, val, wt, dp);
        int take=0;
        if(currWt + wt[ind]<= W){
            take = val[ind] + solve(ind, currVal+ val[ind], currWt+wt[ind], N, W, val, wt, dp);   
        }
        
        return dp[ind][currWt] = max(take, not_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1, vector<int>(W+1, -1));
        return solve(0, 0, 0, N, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends