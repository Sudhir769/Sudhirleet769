//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    
    int countFractions(int n, int num[], int den[])
    {
        map<pair<int,int>, int> m;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int gcd = __gcd(num[i], den[i]);
            
            int a=num[i]/gcd;
            int b=den[i]/gcd;
            int c=b-a;
            
            if(m.count({c,b}))
             ans+=m[{c,b}];
             
            m[{a,b}]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends