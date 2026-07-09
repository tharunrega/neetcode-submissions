class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto v : nums){
            mp[v]++;
        }
        vector<pair<int,int>> vec(mp.begin(),mp.end());

        sort(vec.begin(),vec.end(),comp);
        int cnt = 0;
        for(auto v : vec){
            if(cnt==k) break;
            ans.push_back(v.first);
            cnt++;
        }

        return ans;
    }
};
