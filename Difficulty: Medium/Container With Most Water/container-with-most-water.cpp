//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        
        int left = 0, right = n-1;
        int maxi = 0;
        int curr = 0;
        
        while(left < right){
            curr =  (right - left)*min(arr[left], arr[right]);
            maxi = max(maxi, curr);
            
            if(arr[left] <= arr[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxi;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends