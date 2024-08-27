//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> & nums) {
        int n = nums.size();
        
        vector<int> v1(n, 0), v2(n, 0);
        stack<int> st1, st2;
        st1.push(0), st2.push(0);
        
        for(int i=0; i<n; i++){
            while(!st1.empty() and st1.top() >= nums[i]){
                st1.pop();
            }
            v1[i] = st1.top();
            st1.push(nums[i]);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() and st2.top() >= nums[i]){
                st2.pop();
            }
            v2[i] = st2.top();
            st2.push(nums[i]);
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(ans, abs(v1[i] - v2[i]));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends