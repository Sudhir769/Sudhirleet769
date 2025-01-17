//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);
        unordered_set<int> st;
        
        long long product = 1;
        bool hasZero = false;
        for(int i=0; i<n; i++){
            if(arr[i] != 0) product *= arr[i];
            else st.insert(i), hasZero = true;
        }
        
        if(st.size() >= 2){
            return result;
        }
        
        for(int i=0; i<n; i++){
            if(!hasZero){
                result[i] = product/arr[i];
            }else if(hasZero and st.count(i) == 0){
                result[i] = 0;
            }else{
                result[i] = product;
            }
        }
        return result;
        
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends