//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sum=0;
    long long sumOfDivisors(int n)
    {
        // for(int i=1; i<=n;i++){
        //     int curr=0;
        //     for(int j=1;j<=i;j++){
        //         if(i%j==0) curr+=j;
        //     }
        //     sum+=curr;
        // }
        // return sum;
        
        
        for(long int i=1; i<=n;i++) sum += (n/i)*i;
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends