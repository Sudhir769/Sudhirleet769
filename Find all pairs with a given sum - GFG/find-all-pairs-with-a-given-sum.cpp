//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int n, int M, int X)
    {
        vector<pair<int,int>>ans;
        sort(B, B+M);
        
        for(int i=0;i<n;i++){
            
            int p=X-A[i], flag=0;
            int low=0, high=M-1, mid;
            
            while(low<=high){
                mid=(low+high)/2;
                if(B[mid]==p){
                    flag=1;
                    break;
                }
                if(B[mid]>p)high=mid-1;
                else low=mid+1;
            }
            if(flag)ans.push_back({A[i], B[mid]});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends