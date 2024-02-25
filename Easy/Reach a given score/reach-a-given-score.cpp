//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    set<vector<long long int>>st;
    void solve(int n, int three, int five, int ten){
        if(n == 0){
            st.insert({three, five, ten});
            return;
        }
        if(n < 0) return;
        
        solve(n-3, three+1, five, ten);
        solve(n-5, three, five+1, ten);
        solve(n-10, three, five, ten+1);
        
        return;
    }
    long long int count(long long int n)
    {
        // solve(n, 0, 0, 0);
        // return st.size();
        
        long long int dp[n+1] = {0};
        dp[0] = 1;
        
        vector<int>moves = {3, 5, 10};
        
        for(int move:moves){
            for(int i=move; i<=n; i++){
                dp[i] += dp[i-move];
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends