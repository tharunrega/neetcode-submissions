class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -10;
        int prod = 1;
        for(int i = 0;i<nums.size();i++){
            prod = nums[i]*prod;
            ans = max(prod,ans);
            if(prod==0) prod = 1;
        }

        prod = 1;

        for(int i = nums.size()-1;i>=0;i--){
            prod = nums[i]*prod;
            ans = max(prod,ans);
            if(prod==0) prod = 1;
        }        

        return ans;
    }
};
