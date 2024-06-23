//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string s) {
        int n = s.length();
        vector<int>ans;
        
        int openCnt = 0;
        stack<pair<char, int>>st;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                openCnt++;
                ans.push_back(openCnt);
                st.push({'(', openCnt});
            }else if(s[i] == ')'){
                int closeCnt = st.top().second;
                ans.push_back(closeCnt);
                st.pop();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends