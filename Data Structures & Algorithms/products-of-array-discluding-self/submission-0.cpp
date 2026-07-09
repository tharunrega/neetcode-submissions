class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();        
        vector<int> ans(n);
        vector<int> pre(n+2,1);
        vector<int> suff(n+2,1);

        for(int i=0;i<n;i++){
            pre[i+1]=nums[i]*pre[i];
        }

        for(int i=n-1;i>=0;i--){
            suff[i+1]=nums[i]*suff[i+2];
        }

        cout<<endl;        
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*suff[i+2];
        }

        return ans;

    }
};
