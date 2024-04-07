//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	vector<vector<int>>dp;
	int solve(int i, int j, int a[], int b[]){
	    if(i < 0 and j>=0) return INT_MIN;
	    if(j < 0) return 0;
	    if(dp[i][j] != -1) return dp[i][j];
	    
	    int notTake = solve(i-1, j, a, b);
	    int take = a[i]*b[j] + solve(i-1, j-1, a, b);
	    
	    return dp[i][j] = max(take, notTake);
	}
	
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
// 	    N=n, M=m;
// 	    dp.resize(n+1, vector<vector<int>>(m+1, vector<int>(n-m+1, -1)));
// 		return solve(0, 0, n-m, a, b);

        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        // for(int i=1; i<=m; i++){
        //     for(int j=i; j<=n; j++){
        //         dp[i][j] = max(dp[i-1][j-1] + (a[j-1]*b[i-1]), dp[i][j]);
        //     }
        // }
        // return dp[m][n];
        
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, a, b);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends