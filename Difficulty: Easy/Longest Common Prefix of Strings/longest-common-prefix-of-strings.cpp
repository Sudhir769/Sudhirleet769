//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        if (arr.empty()) {
            return "-1";
        }
    
        string common_prefix = arr[0];
        
        for (int i = 1; i < arr.size(); ++i) {
            int j = 0;
            while (j < common_prefix.size() && j < arr[i].size() && common_prefix[j] == arr[i][j]) {
                ++j;
            }
            common_prefix = common_prefix.substr(0, j);
    
            if (common_prefix.empty()) {
                return "-1";
            }
        }
        
        return common_prefix;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends