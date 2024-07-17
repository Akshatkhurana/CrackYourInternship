class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;

        int sr = 0;
        int ec = col - 1;
        int er = row - 1;
        int sc = 0;
        
        int count = 0;
        int total = row*col; 
        while (count < total) {
            for (int i = sc; i <= ec && count < total; i++) {
                res.push_back(matrix[sr][i]);
                count++;
            }
            sr++;

            for (int i = sr; i <= er && count < total; i++) {
                res.push_back(matrix[i][ec]);
                count++;
            }
            ec--;

            for (int i = ec; i >= sc && count < total; i--) {
                res.push_back(matrix[er][i]);
                count++;
            }
            er--;

            for (int i = er; i >= sr && count < total; i--) {
                res.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        return res;
    }
};
