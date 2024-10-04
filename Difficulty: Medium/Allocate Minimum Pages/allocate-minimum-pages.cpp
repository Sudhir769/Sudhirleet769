//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    
    int solve(int arr[], long long allowedPages, int n){
        int students = 1;
        int pages = 0;
        for(int i=0; i<n; i++){
            if(pages + arr[i] <= allowedPages){
                pages += arr[i];
            }else{
                students++;
                pages = arr[i];
            }
        }
        return students;
    }
    
    long long findPages(int n, int arr[], int m) {
        
        if(m > n) return -1;
        
        long long low = *max_element(arr, arr + n);
        long long high = accumulate(arr, arr+n, 0);
        
        while(low <= high){
            long long mid = (high + low)/2;
            
            int students = solve(arr, mid, n);
            if(students > m){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends