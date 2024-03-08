//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    vector<int> freq(26, 0);
	    for(auto it:s){
	        freq[it-'a']++;
	    }
	    
	    int cnt = 0;
	    int mn = INT_MAX, mx = 0;
	    
	    for(int i=0; i<26; i++){
	        if(freq[i] != 0){
	            mn = min(mn, freq[i]);
	            mx = max(mx, freq[i]);
	        }
	    }
	    if(mx == 0 or (mx == mn)) return true;
	    int cntmn = 0, cntmx = 0;
	    
	    if(abs(mn-mx) > 1) return false;
	    for(int i=0; i<26; i++){
	        if(freq[i] == 0) continue;
	        if(freq[i] == mn) cntmn++;
	        else if(freq[i] == mx) cntmx++;
	        else return false;
	    }
	    if(abs(cntmn - cntmx) > 1 or (mn != 1 and cntmx != 1))return false;
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends