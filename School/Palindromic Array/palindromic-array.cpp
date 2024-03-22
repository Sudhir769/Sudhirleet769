//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    
    bool isPal(string s, int i, int j){
        if(i >= j){
            return true;
        }
        if(s[i] != s[j]){
            return false;
        }
        return isPal(s, i+1, j-1);
    }
    
    int PalinArray(int a[], int n)
    {
    	for(int i=0; i<n; i++){
    	    string s = to_string(a[i]);
    	    if(isPal(s, 0, s.size()-1) == false){
    	        return false;
    	    }
    	}
    	return true;
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends