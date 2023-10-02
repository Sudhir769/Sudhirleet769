//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
  int mod = 1e9+7;
	int distinctSubsequences(string s)
	{
	    int m[26] = {-1};
	    int n=s.length();
	    vector<int> dp(n+1);
	    dp[0]=1;
	    
	    for(int i=0;i<n;i++){
	        if(m[s[i]-'a']!=-1){
	            dp[i+1] = ((dp[i]*2)%mod) - dp[m[s[i]-'a']-1]+mod;
	        }else{
	            dp[i+1]=(dp[i]*2);
	        }
	        m[s[i]-'a']=i+1;
	        dp[i+1]=dp[i+1]%mod;
	    }
	    return dp[n]%mod;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends