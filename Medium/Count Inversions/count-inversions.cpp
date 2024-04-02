//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long cnt = 0;
    void merge(long long int arr[], int low, int mid, int high){
        vector<long long int>temp;
        int i=low, j=mid+1;
        
        while(i <= mid and j<=high){
            
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }else{
                cnt += (mid-i+1);
                temp.push_back(arr[j++]);
            }
        }
        while(i <= mid){
            temp.push_back(arr[i++]);
        }
        while(j <= high){
            temp.push_back(arr[j++]);
        }
        
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }
    
    void mergeSort(long long int arr[], int low, int high){
        if(low >= high) return;
        
        int mid = (low + high)/2;
        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        
        merge(arr, low, mid, high);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr, 0, N-1);
        return cnt;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends