class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0,min_seen = 1e9;

        for(int i = 0;i<n;i++){
            min_seen = min(prices[i],min_seen);
            ans = max(ans , prices[i]-min_seen);
        }
        return ans;
    }
};
