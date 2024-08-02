class Solution {
public:
    void dfs(vector<vector<int>>& ans, int col,int sr,int sc,int newColor,int delRow[], int delCol[]) {
        ans[sr][sc] = newColor;
        int n = ans.size();
        int m = ans[0].size();
        for(int i=0;i<4;i++) {
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            if(nrow >= 0 && nrow < n && ncol < m && ncol >= 0 && ans[nrow][ncol] != newColor && ans[nrow][ncol] == col) {
                dfs(ans,col,nrow,ncol,newColor,delRow,delCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(ans,initialColor,sr,sc,color,delRow,delCol);
        return ans;
    }
};
