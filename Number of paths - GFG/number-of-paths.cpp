//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int i, int j, int n, int m){
        if(i==n or j==m) return 0;
        
        if(i==n-1 and j==m-1) return 1;
        
        return solve(i, j+1, n, m) + solve(i+1, j, n, m);
    }
    long long pow(long long x, int y, long long mod){
        long long res = 1;
        while(y>0){
            if(y % 2 != 0){
                res = (res*x) % mod;
            }
            y = y/2;
            x = (x*x)%mod;
        }
        return res;
    }
    
    long long modInv(long long n, long long mod){
        return pow(n, static_cast<int>(mod-2), mod);
    }
    
    long long  numberOfPaths(int m, int n)
    {
        
        long long ans = 1;
        long long mod = 1000000007LL;
        for(long long i = n; i<= (m+n-2); i++){
            ans = (ans*i)%mod;
            long long invert = modInv(i-n+1, mod);
            ans = (ans*invert)%mod;
        }
        return ans;
        
        
        // int delRow[] = {0,1};
        // int delCol[] = {1,0};
        
        // queue<pair<int,int>>q;
        // q.push({0,0});
        
        // long long cnt=0;
        // while(!q.empty()){
            
        //     int row = q.front().first;
        //     int col = q.front().second;
        //     q.pop();
            
        //     if(row==n-1 and col==m-1){
        //         cnt = (cnt+1)%mod;
        //     }
            
        //     for(int i=0;i<2;i++){
        //         int nrow = row + delRow[i];
        //         int ncol = col + delCol[i];
                
        //         if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
        //             q.push({nrow, ncol});
        //         }
        //     }
        // }
        // return cnt;
        
        // return solve(0, 0, n, m);
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends