//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        
        int start = 0, end = 0;
        int maxstart = 0, maxend = 0;
        int maxi = 0;
        deque<int> mindq;
        deque<int> maxdq;
        
        while(end < n){
            while(!mindq.empty() and arr[mindq.back()] > arr[end]) mindq.pop_back();
            while(!maxdq.empty() and arr[maxdq.back()] < arr[end]) maxdq.pop_back();
            
            mindq.push_back(end);
            maxdq.push_back(end);
            
            while(arr[maxdq.front()] - arr[mindq.front()] > x){
                if(start == mindq.front()) mindq.pop_front();
                if(start == maxdq.front()) maxdq.pop_front();
                start++;
            }
            
            if(end - start > maxend - maxstart){
                maxend = end;
                maxstart = start;
            }
            end++;
        }
        vector<int> ans;
        for(int i=maxstart; i<= maxend; i++){
            ans.push_back(arr[i]);
        }
        return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends