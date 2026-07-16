class Solution {
public:
    int check(vector<int>& piles,int mid){
        int ans = 0;
        for(auto v : piles){
            ans += (v+mid-1)/mid;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int low = 1,high = 1e9;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(piles,mid)<=h){
                ans = mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};
