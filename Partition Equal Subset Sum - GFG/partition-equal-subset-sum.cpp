//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
        if(totalSum%2!=0) return 0;
        
        int targetSum=totalSum/2;
        
        vector<vector<bool>>dp(n+1,vector<bool>(targetSum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        if(arr[0]<=targetSum) dp[0][arr[0]] = 1;
        for(int ind=1;ind<n;ind++){
            for(int target=1; target<=targetSum; target++){
                int notTake = dp[ind-1][target];
                int take = 0;
                if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
                
                dp[ind][target] = take | notTake;
            }
        }
        return dp[n-1][targetSum]; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends