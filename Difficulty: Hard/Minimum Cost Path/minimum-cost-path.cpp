//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    // int n=0, m=0;
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell
	int solve(int i, int j, vector<vector<int>>& grid, 
	        vector<vector<int>>& dp, int n){
	    
	    if(i<0 or j<0 or i>=n or j>=n) return 1e8;
	    if(i==0 and j==0) return grid[i][j];
	    
	    int up = grid[i][j] + solve(i-1, j, grid, dp, n);
	    int left = grid[i][j] + solve(i, j-1, grid, dp, n);
	    int down = grid[i][j] + solve(i+1, j, grid, dp, n);
	    int right = grid[i][j] + solve(i, j+1, grid, dp, n);
	    
	    return min(up, min(left, min(down, right)));
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // n = grid.size();
        // m = grid[0].size();
        
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        
        // return solve(n-1, m-1, grid, dp, n);
        
        int n = grid.size();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        cost[0][0] = grid[0][0];
        
        priority_queue<pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
                greater<pair<int, pair<int,int>>>>pq;
                
        pq.push({cost[0][0], {0,0}});
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!pq.empty()){
            int cst = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            for(int ind=0; ind<4; ind++){
                int nrow = row + delRow[ind];
                int ncol = col + delCol[ind];
                
                if(nrow<0 or nrow>=n or ncol<0 or ncol>=n)  continue;
                
                if(cost[nrow][ncol] > cst + grid[nrow][ncol]){
                    cost[nrow][ncol] = cst + grid[nrow][ncol];
                    pq.push({cost[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return cost[n-1][n-1];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends