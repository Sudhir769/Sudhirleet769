//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
         int n = s.size();
         
         int cnt =1;
         string ans(n+1, ' ');
         
        for(int i=0;i<=n;i++){
            if(i==n or s[i]=='I'){
                for(int j=i-1; j>=-1; j--){
                    ans[j+1] = (char)('0' + cnt);
                    cnt++;
                    if(j>=0 and s[j]=='I') break;
                }
            }
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends