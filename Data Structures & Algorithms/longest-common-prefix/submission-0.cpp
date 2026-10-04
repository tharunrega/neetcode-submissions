class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = 1e9;

        for(int i=0;i<strs.size();i++){
            min_len = min(min_len ,(int)strs[i].size());
        }
        string ans = "";
        for (int i = 0; i < min_len; i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != ch) {
                    return ans;
                }
            }
            ans += ch;
        }

        return ans;
    }
};