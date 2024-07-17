class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Pehle transpose matrix nikal liya fir har row ko reverse kr diya
        for(int i=0;i<n;i++) {
            for(int j=0;j<matrix[0].size()/2;j++) {
                swap(matrix[i][j],matrix[i][matrix[0].size()-1-j]);
            }
        }
    }
};
