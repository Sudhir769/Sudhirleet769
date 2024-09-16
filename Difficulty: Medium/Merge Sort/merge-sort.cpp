//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int low, int mid, int high)
    {
        int left = low;
        int right = mid+1;
        
        vector<int> temp(high-low+1);
        int cnt = 0;
        
        while(left <= mid and right <= high){
            if(arr[left] <= arr[right]){
                temp[cnt++] = arr[left++];
            }else{
                temp[cnt++] = arr[right++];
            }
        }
        
        while(left <= mid) temp[cnt++] = arr[left++];
        while(right <= high) temp[cnt++] = arr[right++];
        
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
        
    }
    public:
    void mergeSort(int arr[], int left, int right)
    {
        if(left >= right) return;
        
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends