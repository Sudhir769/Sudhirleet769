//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int cnt = 0;
    void merge(vector<long long> &arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        
        vector<long long> temp;
        
        while(left <= mid and right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }else{
                cnt += (mid - left + 1);
                temp.push_back(arr[right++]);
            }
        }
        
        while(left <= mid) temp.push_back(arr[left++]);
        while(right <= high) temp.push_back(arr[right++]);
        
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }
    
    void ms(vector<long long> &arr, int low, int high){
        if(low >= high) return;
        
        int mid = (low + high)/2;
        
        ms(arr, low, mid);
        ms(arr, mid+1, high);
        
        merge(arr, low, mid, high);
    }
    
    long long int inversionCount(vector<long long> &arr) {
        long long n = arr.size();
        ms(arr, 0, n-1);
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends