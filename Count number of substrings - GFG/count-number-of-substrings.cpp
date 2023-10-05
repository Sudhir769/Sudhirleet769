//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  long long int help(string s, int k){
      int i=0, j=0;
    	int n = s.size();
    	long long ans=0;
    	int arr[26] = {0};
    	int dcount=0;
    	
    	while(j<n){
    	    arr[s[j]-'a']++;
    	    if(arr[s[j]-'a']==1) dcount++;
    	    
    	    while(dcount>k){
    	        arr[s[i]-'a']--;
    	        if(arr[s[i]-'a']==0) dcount--;
    	        i++;
    	    }
    	    j++;
    	    ans += (j-i+1);
    	}
    	return ans;
  }
    long long int substrCount (string s, int k) {
    	return help(s,k) - help(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends