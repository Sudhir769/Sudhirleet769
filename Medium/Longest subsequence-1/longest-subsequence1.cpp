//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int n, vector<int> &a,int prev,int i){
      if(i>=n){
          return 0;
      }
      if(prev==-1){
         return max(1+solve(n,a,i,i+1),0+solve(n,a,prev,i+1));
      }
      
      int ans=0,ans2=0;
      if(abs(a[prev]-a[i])==1){
          ans=1+solve(n,a,i,i+1);
      }
      
      ans2=0+solve(n,a,prev,i+1);
      
      return max(ans,ans2);
      
    }
    int longestSubseq(int n, vector<int> &a) {
        
        return solve(n,a,-1,0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends