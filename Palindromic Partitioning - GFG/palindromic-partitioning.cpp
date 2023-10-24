//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>dp;
    bool isPalin(string str, int i, int j){
        while(i<j){
            if(str[i]==str[j]){
                i++, j--;
            }else{
                return false;
            }
        }
        return true;
    }
    
    int helper(string str, int i, int n){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int result = INT_MAX;
        
        for(int j = i; j < n; j++){
            if(isPalin(str, i, j)){
                int cost = 1 + helper(str, j+1, n);
                result = min(result, cost);
            }
        }
        return dp[i] = result;
    }
    
    int palindromicPartition(string str)
    {
        int n = str.size();
        dp.resize(n, -1);
        
        return helper(str, 0, n) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends