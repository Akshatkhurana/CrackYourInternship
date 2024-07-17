class Solution {
public:
    void SetAllZeroes(vector<vector<int>> &matrix,int n,int m,vector<vector<int>> &vis) {
        //for n
        for(int j=0;j<matrix[0].size();j++) {
            if(matrix[n][j] == 0) {
            	//
			}
			else {
				vis = 1;
				 mat = 0;
			}
        }
        //for m
        for(int i=0;i<matrix.size();i++) {
            if(matrix[i][m] != 0) {
                vis[i][m] = 1;
            }
            matrix[i][m] = 0; 
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> vis(row, vector<int> (col,0));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(!vis[i][j] && matrix[i][j] == 0) {
                    SetAllZeroes(matrix,i,j,vis);
                }
            }
        }
    }
};
