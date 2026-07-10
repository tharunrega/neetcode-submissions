class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for (int num : s) {
            if (s.count(num - 1))
                continue;
            int len = 1;
            int curr = num;
            while (s.count(curr + 1)) {
                curr++;
                len++;
            }
            ans = max(ans, len);
        }

        return ans;
    }
};
