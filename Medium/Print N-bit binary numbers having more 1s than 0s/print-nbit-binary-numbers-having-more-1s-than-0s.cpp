//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector<string>ans;
    void solve(int one, int zero, string s, int n){
        if(one < zero){
            return;
        }
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        
        solve(one+1, zero, s+'1', n);
        solve(one, zero+1, s+'0', n);
    }
	vector<string> NBitBinary(int n)
	{
	    solve(1, 0, "1", n);
	    return ans;
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends