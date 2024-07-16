//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/
        //{ Driver Code Starts
class Solution {
public:
    vector<int> previousSmaller(vector<int> &nums, int n) {
        stack<int> st;
        vector<int> res(n, -1);  // Initialize the result vector with -1
        st.push(-1);
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            while (st.top() != -1 && nums[st.top()] >= curr) {
                st.pop();
            }
            res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> nextSmaller(vector<int> nums, int n) {
        stack<int> st;
        vector<int> res(n, n);  // Initialize the result vector with n
        st.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int curr = nums[i];
            while (st.top() != -1 && nums[st.top()] >= curr) {
                st.pop();
            }
            res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    int largestArea(vector<int> nums) {
        int n = nums.size();

        vector<int> prevEle = previousSmaller(nums, n);
        vector<int> nextEle = nextSmaller(nums, n);

        int area = 0;  // Initialize area to 0
        for (int i = 0; i < n; i++) {
            int l = nums[i];
            if (nextEle[i] == -1) {
                nextEle[i] = n;
            }
            int b = nextEle[i] - prevEle[i] - 1;
            int newArea = l * b;
            area = max(newArea, area);
        }
        return area;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> height(m, 0);
        int maxi = 0;  // Initialize maxi to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] == 1) {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            maxi = max(maxi, largestArea(height));
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
