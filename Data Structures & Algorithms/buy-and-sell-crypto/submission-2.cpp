class Solution {
public:
     
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxheight = prices[n-1];
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            ans = max(ans,maxheight-prices[i]);
            maxheight = max(maxheight,prices[i]);
        }

        return ans;
    }
};
