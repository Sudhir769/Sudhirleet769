
class Solution {
  public:
    void dfs(int sr, int sc, vector<vector<int>>&ans, vector<vector<int>>&image,
        int newColor, int delRow[], int delCol[], int iniColor){
            int n = ans.size();
            int m = ans[0].size();
            
            ans[sr][sc]=newColor;
            
            for(int i=0;i<4;i++){
                int nrow = sr + delRow[i];
                int ncol = sc + delCol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and
                    ans[nrow][ncol]!=newColor and image[nrow][ncol]==iniColor){
                        dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
                    }
            }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,  int newColor) {
        int iniColor = image[sr][sc];
        
        vector<vector<int>>ans=image;
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
        
        return ans;
    }
};

