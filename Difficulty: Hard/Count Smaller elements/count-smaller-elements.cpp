//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    vector<int>bits;
    void update(int i){
        i++;
        while(i < bits.size()){
            bits[i]++;
            i += i&-i;
        }
    }
    
    int query(int i){
        i++;
        int sum = 0;
        while(i > 0){
            sum += bits[i];
            i -= i&-i;
        }
        return sum;
    }
    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        bits.resize(n+1);
        vector<int>ans(n);
        vector<vector<int>>temp;
        
        for(int i=0; i<n; i++){
            temp.push_back({arr[i], i});
        }
        
        sort(temp.begin(), temp.end());
        for(int i=0; i<n; i++){
            ans[temp[i][1]] = i - query(temp[i][1]);
            update(temp[i][1]);
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends