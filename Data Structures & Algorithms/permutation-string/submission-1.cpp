class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26]={0};
        int freq2[26]={0};
        int k = s1.size();
        int n = s2.size();
        for(int i=0;i<k;i++){
            freq1[s1[i]-'a']++;
        }
        
        int tail =0,head=-1;
        while(head+1<n){
            while(head+1<n && head-tail+1 < k){
                head++;
                freq2[s2[head]-'a']++;
            }
            bool ok = true;

            for(int i =0;i<26;i++){
                if(freq1[i]!=freq2[i]){
                    ok = false;
                    break;
                }
            }
            if(ok) return true;

            if (tail <= head) {
                freq2[s2[tail] - 'a']--;
                tail++;
            } else {
                tail++;
                head = tail - 1;
            }
        }
        return false;
    }
};
