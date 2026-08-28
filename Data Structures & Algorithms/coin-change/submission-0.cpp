class Solution {
public:
    vector<vector<int>> dp;
    int rec(int level,int amount,vector<int>& coins){
        if (amount == 0) return 0;
        if (level < 0 || amount < 0) return 1e9;
        if(dp[level][amount] != -1) return dp[level][amount];
        int rem = amount/coins[level];
        int take = 1 + rec(level,amount - coins[level],coins);
        int skip = rec(level-1,amount,coins);

        return dp[level][amount] = min(take,skip); 
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(15,vector<int>(10005,-1));
        int n = coins.size();
        int ans = rec(n-1,amount,coins);  

        return ans >=1e9 ? -1 : ans; 
    }
};
