class Solution {
public:
    int maxArea(vector<int>& vec) {
        int n= vec.size();
        int l = 0,r = n-1;
        int ans = 0;
        while(l<r){
            int len = r-l;
            ans = max(ans,min(vec[l],vec[r])*len);
            if(vec[l]<vec[r]) l++;
            else r--;

        }
        return ans;
    }
};
