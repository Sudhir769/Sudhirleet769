//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    int f(int i,int j,int arr[MAX][MAX],int n,int m,int k,int &cnt){
        int x=i,y=j;
        for(int a=y;a<m;a++){
            cnt++;
            if(cnt==k)return arr[x][a];
        }
        for(int a=i+1;a<n;a++){
            cnt++;
            if(cnt==k)return arr[a][m-1];
        }
        for(int a=m-2;a>=y;a--){
            cnt++;
            if(cnt==k)return arr[n-1][a];
        }
        for(int a=n-2;a>x;a--){
            cnt++;
            if(cnt==k)return arr[a][y];
        }
        return -1e9;
    }
    
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		 int cnt=0;
         for(int i=0;i<n;i++){
             int ans= f(i,i,a,n-i,m-i,k,cnt);
             if(ans!=-1e9)return ans;
         }
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends