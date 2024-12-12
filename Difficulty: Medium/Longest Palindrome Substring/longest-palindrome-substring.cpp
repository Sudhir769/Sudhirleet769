//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPalindrome(string &s, int n){
        int start = 0;
        int end = n-1;
        
        while(start < end){
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    
    string longestPalindrome(string& s) {
        int n = s.length();
        int resultSize = INT_MIN;
        string result = "";
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string substr = s.substr(i, j-i+1);
                int len = substr.length();
                if(isPalindrome(substr, len)){
                    if(resultSize < len){
                        result = substr;
                        resultSize = len;
                    }
                }
            }
        }
        return result;   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends