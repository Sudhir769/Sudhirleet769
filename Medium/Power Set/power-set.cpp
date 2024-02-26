//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>ans;
	void solve(int ind, string temp, string s, int n){
	    if(ind >= n){
	        ans.push_back(temp);
	        return;
	    }

	    solve(ind+1, temp + s[ind] ,s ,n);
	    solve(ind+1, temp, s, n);
	}
	vector<string> AllPossibleStrings(string s){
	   int n = s.length();
	   
	   solve(0, "", s, n);
	   
	   sort(ans.begin(), ans.end());
	   ans.erase(ans.begin()+0);
	   return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends