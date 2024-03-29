//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
            
    long long int count(int coins[], int N, int sum) {

        vector<long long int>dp(sum+1,0);
        
        for(int i=0;i<=sum;i++){
            if(i%coins[0]==0){
                dp[i]=1;
            }
        }
        
        for(int i=1;i<N;i++){
            vector<long long int> curr(sum+1,0);
            for(int j=0;j<=sum;j++){
                long long int a,b;
                a=b=0;
                a=dp[j];
                if(j>=coins[i]){
                    b=curr[j-coins[i]];
                }
                curr[j]=a+b;
            }
            
            dp=curr;
        }
        return dp[sum];
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends