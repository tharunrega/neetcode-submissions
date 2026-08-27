class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int rec(int i,int j,string word1,string word2){
        if(i==n && j == m){
            return 0;
        }
        if(i==n) {
            return m-j;
        }
        if(j==m) {
            return n-i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if(word1[i]==word2[j]) {
            ans = rec(i+1,j+1,word1,word2);
        }
        ans = min(ans,1+rec(i,j+1,word1,word2));
        ans = min(ans,1+rec(i+1,j,word1,word2));
        ans = min(ans,1+rec(i+1,j+1,word1,word2));
        
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        dp.assign(101,vector<int>(101,-1));
        n = word1.size();
        m = word2.size();
        return rec(0,0,word1,word2);
    }
};
