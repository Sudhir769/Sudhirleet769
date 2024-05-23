//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int fun(string &s,int i,int j){
        if(i >= j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]){
            dp[i][j] = 1+min(fun(s,i,j-1),fun(s,i+1,j));
        }
        else dp[i][j] = fun(s,i+1,j-1);
        return dp[i][j];
    }
    int kPalindrome(string str, int n, int k)
    {
        dp.resize(n,vector<int>(n,-1));
        return fun(str,0,n-1)<=k;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends