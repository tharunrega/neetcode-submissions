class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int bit_cnt = 0;
            for(int j=31;j>=0;j--){
                if(i & (1<<j)){
                    bit_cnt++;
                }
            }
            ans.push_back(bit_cnt);
        }
        return ans;
    }
};
