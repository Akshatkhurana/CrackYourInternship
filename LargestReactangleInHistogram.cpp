class Solution {
public:
    vector<int> nextSmaller(vector<int> &nums,int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--) {
            int curr = nums[i];
            while(st.top() != -1 && nums[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> previousSmaller(vector<int> &nums,int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            int curr = nums[i];
            while(st.top() != -1 && nums[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevEle(n);
        vector<int> nextEle(n);

        prevEle = previousSmaller(heights,n);
        nextEle = nextSmaller(heights,n);

        int area = INT_MIN;
        for(int i=0;i<n;i++) {
            int l = heights[i];
            
            if(nextEle[i] == -1) {
                nextEle[i] = n;
            }
            int b = nextEle[i] - prevEle[i] - 1;
            
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
};
