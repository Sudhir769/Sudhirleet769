//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int isPossible(vector<int>& arr, int n, int k, int mid) {
        int studentCount = 1;
        int currentSum = 0;
    
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                return 0; 
            }
            if (currentSum + arr[i] > mid) {
                studentCount++; 
                currentSum = arr[i];
                if (studentCount > k) {
                    return 0; 
                }
            } else {
                currentSum += arr[i];
            }
        }
        return 1;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if (n < k) {
            return -1; 
        }
    
        int sum = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    
        int low = max;
        int high = sum;
        int result = -1;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, n, k, mid)) {
                result = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends