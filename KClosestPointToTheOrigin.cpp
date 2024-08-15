class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue < pair<int,int> > pq;
        for (int i = 0; i < points.size(); i++) {
            int dist =
                points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dist, i});
        }
        while(pq.size() > k) {
            pq.pop();
        }
        while(!pq.empty()) {
            int idx = pq.top().second;
            res.push_back({points[idx]});
            pq.pop();
        }
        return res;
    }
};
