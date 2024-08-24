class Solution {
public:
    // int solve(vector<int>& heights, int bricks, int ladders, int idx) {
    //     if (idx == heights.size()-1) {
    //         return 0;
    //     }
    //     if (heights[idx + 1] <= heights[idx]) {
    //         return 1 + solve(heights, bricks, ladders, idx + 1);
    //     } else {
    //         int bybrick = 0;
    //         int byladder = 0;
    //         int diff = heights[idx + 1] - heights[idx];
    //         if (diff <= bricks) {
    //             bybrick = 1 + solve(heights, bricks - diff, ladders, idx + 1);
    //         }
    //         if (ladders > 0) {
    //             byladder = 1 + solve(heights, bricks, ladders - 1, idx + 1);
    //         }
    //         return max(byladder, bybrick);
    //     }
    //     return -1;
    // }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int i=0;
        priority_queue<int> pq;
        for(;i<n-1;i++) {
            if(heights[i+1] <= heights[i]) {
                continue;
            }
            int diff = heights[i+1] - heights[i];
            if(bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            }
            else if(ladders > 0) {
                if(!pq.empty()) {
                    int max_bricks_used_in_past = pq.top();
                    if(max_bricks_used_in_past > diff) {
                        bricks += max_bricks_used_in_past;
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            else {
                break;
            }
        }
        return i;
    }
};
