//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    int cnt = 0;
	    int p = n-1, q = n-1;
	    int i=0, j=0;
	    
	    while(i<n and p>=0){
	        while(j<n and q>=0){
	        int sum = mat1[i][j] + mat2[p][q];
	            if(sum == x){
	                cnt++;
	                j++, q--;
	            }else if(sum > x){
	                q--;
	            }else{
	                j++;
	            }
	        }
	        if(q<0){
	            q = n-1;
	            p--;
	        }
	        if(j==n){
	            j=0;
	            i++;
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends