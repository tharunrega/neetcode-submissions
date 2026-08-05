class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        multimap<long long, int> mp;

        for (int i = 0; i < points.size(); i++) {
            long long distance = 1LL * points[i][0] * points[i][0]
                               + 1LL * points[i][1] * points[i][1];
            mp.insert({distance, i});
        }

        auto it = mp.begin();

        for (int i = 0; i < k; i++) {
            ans.push_back(points[it->second]);
            ++it;
        }

        return ans;
    }
};