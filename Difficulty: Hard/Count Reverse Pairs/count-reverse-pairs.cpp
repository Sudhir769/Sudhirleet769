//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int cnt = 0;
    void m(vector<int> &arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        
        vector<int> temp;
        while(left <= mid and right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
            }
        }
        while(left <= mid) temp.push_back(arr[left++]);
        while(right <= high) temp.push_back(arr[right++]);
        
        for(int i=low; i<= high; i++){
            arr[i] = temp[i-low];
        }
    }
    
    void count(vector<int> &arr, int low, int mid, int high){
        int j = mid+1;
        long long two = 2;
        for(int i=low; i<=mid; i++){
            while(j <= high and arr[i] > arr[j]* two){
                j++;
            }
            cnt += (j-mid-1);
        }
    }
    
    void ms(vector<int> &arr, int low, int high){
        if(low >= high) return;
        
        long long mid = low + (high - low)/2;
        
        ms(arr, low, mid);
        ms(arr, mid+1, high);
        
        count(arr, low, mid, high);
        m(arr, low, mid, high);
    }
    
    int countRevPairs(int n, vector<int> &arr) {
        ms(arr, 0, n-1);
        return cnt;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends