class Solution {
public:
    int n;
    vector<int> dp;
    int rec(int level , vector<int>& nums){
        if(level>=n) return 0;
        if(dp[level] != -1) return dp[level];
        int ans = nums[level];
        for(int ch = 2 ;ch<n;ch++){
            ans = max(ans,nums[level] + rec(level+ch,nums));
        }
        return dp[level]= ans;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(105,-1);
        return max(rec(0,nums),rec(1,nums));
    }
};
