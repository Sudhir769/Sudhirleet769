//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod=1e9+7;
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long a,b,c,d;
        a=1, b=2, c=4, d=0;
        if(n==1) return a;
        if(n==2) return b;
        if(n==3) return c;
        
        for(int i=4;i<=n;i++){
            d = (((a%mod + b%mod)%mod + c%mod)%mod);
            
            a=b;
            b=c;
            c=d;
        }
        return d;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends