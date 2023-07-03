//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int i=0;
        int j=0;
        int maxDiff=-1;
        
        int lmin[n];
        int rmax[n];
        
        lmin[0]=arr[0];
        for(i=1;i<n;i++){
            lmin[i]=min(arr[i],lmin[i-1]);
        }
        
        rmax[n-1]=arr[n-1];
        for(j=n-2;j>=0;j--){
            rmax[j]=max(arr[j],rmax[j+1]);
        }
        
        j=0,i=0;
        while(j<n && i<n){
            if(lmin[i]<=rmax[j]){
                maxDiff=max(maxDiff,j-i);
                j++;
            }else{
                i++;
            }
        }
        
        return maxDiff;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends