//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        long long maxBooks = 0;
        long long currentBooks = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                currentBooks += arr[i];
                maxBooks = max(maxBooks, currentBooks);
            } else {
                currentBooks = 0; 
            }
        }
        return maxBooks;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends