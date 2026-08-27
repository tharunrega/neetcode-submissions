class Solution {
public:
    string s;
    vector<vector<int>> dp;

    int rec(int l, int r) {
        if(l >= r) {
            return 1;
        }

        if(dp[l][r] != -1) {
            return dp[l][r];
        }

        if(s[l] == s[r] && rec(l + 1, r - 1)) {
            return dp[l][r] = 1;
        }

        return dp[l][r] = 0;
    }

    string longestPalindrome(string s) {
        this->s = s;

        int n = s.size();

        dp.assign(n, vector<int>(n, -1));

        int start = 0;
        int len = 1;

        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {

                if(rec(l, r)) {
                    if(r - l + 1 > len) {
                        len = r - l + 1;
                        start = l;
                    }
                }
            }
        }

        return s.substr(start, len);
    }
};