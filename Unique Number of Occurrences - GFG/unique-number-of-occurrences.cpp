//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    unordered_map<int,int> occ;
    set<int> s;
    bool isFrequencyUnique(int n, int arr[])
    {
        for(int i=0;i<n;i++){
            occ[arr[i]]++;
        }
        
        for(auto i : occ){
            s.insert(i.second);
        }
        
        if(occ.size()==s.size()){
            return true;
        }else{
            return false;
        }
        
        
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends