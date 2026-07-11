  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int head = -1, tail = 0;
        int freq[256] = {0};
        int ans = 0;
        while(head+1<n){
            while(head+1<n && freq[s[head+1]]==0){
                head++;
                freq[s[head]]++;
            }
            ans = max(ans,head-tail+1);
            while(head+1< n && freq[s[head+1]]==1){
                freq[s[tail]]--;
                tail++;
            }
            if(tail>head){
                head = tail - 1;
            }
            
        }

        return ans;
    }
};
