//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int cnt = 0;
    void merge(vector<int>& arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int> temp;
        
        
        while(left <= mid and right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= high){
            temp.push_back(arr[right++]);
        }
        
        for(int i=low; i<= high; i++){
            arr[i] = temp[i-low];
        }
        
    }
    
    void mergeSort(vector<int>&arr, int left, int right){
        if(left >= right) return;
        
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        mergeSort(arr, 0, n-1);
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends