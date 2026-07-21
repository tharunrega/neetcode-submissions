class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int lo = 0,hi= n-1;
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]>=nums[lo]){
                if(nums[mid]>=nums[hi]){
                    lo = mid+1;
                }else{
                   hi = mid;
                }
            }
            else if(nums[mid]<=nums[lo]){
                if(nums[mid]>=nums[hi]){
                    lo = mid+1;
                }
                else{
                    hi = mid;
                }
            }
            ans = mid;
        }
        return nums[ans];
    }
};
