//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string str) {
        //AAANAMANMM&MMNANANAAA
        
        string rev = str;
        reverse(rev.begin(), rev.end());
        str+='$';
        str+=rev;
        int size=str.size();
        vector<int>lps(size, 0);
        
        int prefix=0, suffix=1;
        
        while(suffix < size){
            if(str[suffix] == str[prefix]){
                lps[suffix] = prefix + 1;
                suffix++, prefix++;
            }else{
                if(prefix==0) suffix++;
                else prefix = lps[prefix-1];
            }
        }
        return rev.size()-lps[size-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends