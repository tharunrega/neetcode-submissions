class Solution {
public:
    vector<vector<bool>> dp;
    string longestPalindrome(string s) {
        int n = s.size();
        dp.assign(n+1,vector<bool>(n+1,false));
        int start = 0;
        int maxlen = 1;
        for(int len = 1 ; len<=n ; len++){
            for(int l = 0; l+len-1<n ;l++){
                int r = l + len -1;
                if(len==1) dp[l][r] = true;
                else if(len==2){
                    dp[l][r] = (s[l]==s[r]);
                }
                else{
                    dp[l][r] = (s[l] == s[r]) && dp[l+1][r-1];
                }

                if(dp[l][r] && len > maxlen){
                    start = l;
                    maxlen = len;
                }
            }
        }

        return s.substr(start,maxlen);
    }
};
