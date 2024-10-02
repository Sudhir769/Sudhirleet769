//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        deque<int> dq;
        int n = arr.size();
        
        for(auto num:arr){
            dq.push_back(num);
        }
        int k = 1;
        while(n > k){
            int num = dq.back();
            dq.pop_back();
            dq.push_front(num);
            dq.erase(dq.begin() + n - k);
            k++;
            n--;
        }
        return dq[0];
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends