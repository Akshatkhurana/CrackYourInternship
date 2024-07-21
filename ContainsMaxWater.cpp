class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int maxi = INT_MIN;
        while(i < j) {
            int len = min(height[i],height[j]);
            int bred = j - i;
            int area = len * bred;
            maxi = max(area,maxi);
            if(height[i] < height[j]) {
                i++;
            }
            else 
            j--;
        }
        return maxi;
    }
};
