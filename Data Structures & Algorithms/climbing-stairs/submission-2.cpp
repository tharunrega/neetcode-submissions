class Solution {
public:
    int N;
    vector<int> dp;
    int rec(int level){
        if(level>N) return 0;
        if(level==N){
            return 1;
        }
        if(dp[level] != -1) return dp[level];
        //step 1 and 2
        int ans = rec(level+1) + rec(level+2);
        return dp[level] = ans;

    }
    int climbStairs(int n) {
        this->N = n;
        dp.assign(50,-1);
        return rec(0);
    }
};
