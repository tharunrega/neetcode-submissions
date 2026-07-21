class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        string ans = "";
        int freq[256] = {0};

        for (char c : t)
            freq[c]++;

        int tail = 0, head = -1;
        int cnt = 0;
        int len = INT_MAX;

        while (head + 1 < n || cnt == m) {

            while (head + 1 < n && cnt < m) {
                head++;
                freq[s[head]]--;
                if (freq[s[head]] >= 0)
                    cnt++;
            }

            while (tail <= head && cnt == m) {
                if (head - tail + 1 < len) {
                    len = head - tail + 1;
                    ans = s.substr(tail, len);
                }

                freq[s[tail]]++;
                if (freq[s[tail]] > 0)
                    cnt--;

                tail++;
            }
        }

        return ans;
    }
};