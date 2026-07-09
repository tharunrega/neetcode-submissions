class Solution {
public:
    int n;
    int dp[46];
    int rec(int level){
        //pruning
        if(level > n) return 0;
        //base case
        if(level==n) return 1;
        //cache check
        if(dp[level]!= -1) return dp[level];
        //compute
        int ans = rec(level+1) + rec(level+2);
        //save and return
        return dp[level] = ans;
    }
    int climbStairs(int N) {
        n = N;
        for(int i=0;i<=n;i++) dp[i] = -1;
        return rec(0);       
    }
};