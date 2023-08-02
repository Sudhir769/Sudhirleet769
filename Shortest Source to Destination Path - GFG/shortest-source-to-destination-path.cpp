//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Pair{
    int x, y, d;
    Pair(int x, int y, int d){
        this->x=x;
        this->y=y;
        this->d=d;
    }
};
class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        
        queue<Pair>q;
        vector<vector<bool>>vis(N, vector<bool>(M, false));
        
        q.push(Pair(0,0,0));
        vis[0][0]=true;
        
        while(!q.empty()){
            Pair curr=q.front();
            q.pop();
            
            if(curr.x==X && curr.y==Y){
                return curr.d;
            }
            
            for(int i=0;i<4;i++){
                int nx=dx[i]+curr.x;
                int ny=dy[i]+curr.y;
                
                if(nx>=0 && nx<N && ny>=0 && ny<M && A[nx][ny]==1 && !vis[nx][ny]){
                    vis[nx][ny]=true;
                    q.push(Pair(nx,ny,curr.d+1));
                }
            }
        }
        return -1;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends