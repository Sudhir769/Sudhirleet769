//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        vector<int> freq(26, 0);
        for(char ch:s1){
            freq[ch-'a']++;
        }
        
        for(char ch:s2){
            freq[ch-'a']--;
        }
        
        for(int i=0; i<26; i++){
            if(freq[i] < 0 or freq[i] > 0){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends