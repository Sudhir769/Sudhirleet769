//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) { 
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_set<int> st;
        int sum = 0, maxi = 0;
        
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i]);
            if(st.count(arr[i])){
                sum += maxi - arr[i] + 1;
                maxi++;
                st.insert(maxi);
            }else{
                st.insert(arr[i]);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends