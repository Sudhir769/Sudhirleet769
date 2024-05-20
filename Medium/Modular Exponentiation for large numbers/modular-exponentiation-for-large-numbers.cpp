//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int result = 1;
		    
		    while(n > 0){
		        if(n % 2 == 1){
		            result  = (result * x) % M;
		            n = n-1;
		        }else{
		            x = (x * x) % M;
		            n = n / 2;
		        }
		    }
		    return result % M;
		}
		
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends