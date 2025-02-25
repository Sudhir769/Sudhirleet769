//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        
        int maxArea = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() and arr[i] < arr[st.top()]){
                int ind = st.top();
                st.pop();
                
                int pse = st.empty() ? -1:st.top();
                maxArea = max(maxArea, arr[ind]*(i - pse - 1));
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int ind = st.top(); st.pop();
            int pse = st.empty() ? -1:st.top();
            maxArea = max(maxArea, arr[ind] * (n - pse - 1));
        }
        return maxArea;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends