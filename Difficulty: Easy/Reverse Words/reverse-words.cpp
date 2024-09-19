//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        int n = str.length();
        
        string result = "";
        int j=n-1;
        
        for(int i=n-1; i>=0; ){
            while(j>=0 and str[j] != '.'){
                j--;
            }
            result += str.substr(j+1, i-j);
            result.push_back('.');
            j--;
            i=j;
        }
        result.pop_back();
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends