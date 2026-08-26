class Solution {
public:
    int n;
    vector<int> dp;
    vector<int> vec;
    int rec(int level){
        if(level>=n){
            return 0;
        }
        if(dp[level] != -1) return dp[level];
        int ans = vec[level] + rec(level+1);
        if(level + 1 < n) ans = min(ans,vec[level] + rec(level+2));

        return dp[level] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        this->vec = cost;
        dp.assign(101,-1);
        n = cost.size();
        return min(rec(0),rec(1));
    }
};
