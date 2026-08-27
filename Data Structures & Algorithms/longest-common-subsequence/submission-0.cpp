class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i, int j,string text1, string text2){
        if(i == text1.length() || j == text2.length()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(text1[i]==text2[j]){
            ans = 1 + rec(i+1,j+1,text1,text2);
        }
        ans = max(ans,rec(i+1,j,text1,text2));
        ans = max(ans,rec(i,j+1,text1,text2));

        return dp[i][j]= ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(1001,vector<int>(1001,-1));
        return rec(0,0,text1,text2);
    }
};
