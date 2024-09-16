//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Write your code here

class Solution {
  public:
    vector<int> mergeNsort(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<int> ans(n+m);
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int i=0, j=0, k=0;
        for(; i<n and j<m; k++){
            if(a[i] == b[j]){
                ans[k] = a[i++];
                j++;
                ans.pop_back();
            }else if(a[i] < b[j]){
                ans[k] = a[i++];
            }else{
                ans[k] = b[j++];
            }
        }
        while(i<n) ans[k++] = a[i++];
        while(j<m) ans[k++] = b[j++];
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr, brr;
        string input1, input2;

        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }

        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }

        Solution ob;
        vector<int> res = ob.mergeNsort(arr, brr);

        for (int x : res) {
            cout << x << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends