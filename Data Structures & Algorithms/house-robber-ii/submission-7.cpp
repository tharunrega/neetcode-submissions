class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(int level,vector<int>& nums,int first) {
        if(level>=n || (first ==1 && level ==n-1)) return 0;

        if(dp[level][first] != -1) return dp[level][first];
        int ans = rec(level+1,nums,first);

        ans = max(ans,rec(level+2,nums,first)+nums[level]);

        return dp[level][first] = ans;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(105,vector<int>(2,-1));
        if(n==1) return nums[0];

        return max(rec(0,nums,1),rec(1,nums,0));


    }
};
