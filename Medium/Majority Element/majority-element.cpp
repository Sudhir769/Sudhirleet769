//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int nums[], int n)
    {
        int el = 0, cnt = 0;
        
        for(int i=0; i<n; i++){
            if(cnt==0){
                el = nums[i];
                cnt = 1;
            }else if(nums[i] == el){
                cnt++;
            }else{
                cnt--;
            }
        }
        cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == el){
                cnt++;
            }
        }
        
        return cnt > n/2 ? el:-1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends