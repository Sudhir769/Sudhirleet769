//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int> freq(26, 0);
        for(auto ch:p){
            freq[ch - 'a']++;
        }
        
        int req = p.length();
        int i=0, j=0, n = s.length();
        
        if(req > n) return "-1";
        int minSize = INT_MAX;
        int sp = 0;
        
        while(j < n){
            if(freq[s[j] - 'a'] > 0) req--;
            
            freq[s[j] - 'a']--;
            while(req == 0){
                int currSize = j-i+1;
                if(currSize < minSize){
                    minSize = currSize;
                    sp = i;
                }
                freq[s[i] - 'a']++;
                if(freq[s[i] - 'a'] > 0){
                    req++;
                }
                i++;
            }
            j++;
        }
        return minSize == INT_MAX ? "-1":s.substr(sp, minSize);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends