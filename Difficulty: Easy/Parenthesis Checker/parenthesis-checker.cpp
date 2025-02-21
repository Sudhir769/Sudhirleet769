//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        int n = s.length();
        
        stack<char> st;
        unordered_set<char> set = {'(', '[', '{'};
        for(int i=0; i<n; i++){
            if(set.count(s[i])){
                st.push(s[i]);
            }else{
                if(!st.empty() and ((s[i] == ')' and st.top() == '(') or
                (s[i] == ']' and st.top() == '[') or
                (s[i] == '}' and st.top() == '{')) ){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends