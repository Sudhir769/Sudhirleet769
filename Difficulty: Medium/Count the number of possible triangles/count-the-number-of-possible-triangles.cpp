//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // 1 + 3 + 1 + 1
        int n = arr.size();
        int ans = 0;
        sort(arr.begin(), arr.end());
        
        for(int j=n-1; j>=0; j--){
            for(int i=j-1; i>0; i--){
                int cnt = 0;
                int k = i-1;
                // 3 4 6 7
                while(k >= 0 and arr[i] + arr[k] > arr[j]){
                    cnt++;
                    k--;
                }
                ans += cnt;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends