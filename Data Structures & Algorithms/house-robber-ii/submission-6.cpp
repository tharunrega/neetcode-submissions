class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(int level,vector<int>& nums,int first) {
        if(level>=n) return 0;
        if(dp[level][first] != -1) return dp[level][first];
        int ans = nums[level];
        for(int ch = 2;ch<n;ch++){
            if(first==1 && level+ch == n-1) continue;
            ans = max(ans,rec(level+ch,nums,first) + nums[level]);
        } 

        return dp[level][first] = ans;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(105,vector<int>(2,-1));
        int ans = 0;

        for(int i=0;i<n;i++){
            ans = max(ans,rec(i,nums,(i==0)? 1 : 0));
        }
        return ans;
    }
};
