class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int index = (n+m)/2;
        if(m==0){
            if(n%2==1){
                return nums2[n/2];
            }else{
                return (nums2[index] + nums2[index-1])/2.0;
            }
        }

        if(n==0){
            if(m%2==1){
                return nums1[m/2];
            }else{
                return (nums1[index] + nums1[index-1])/2.0;
            }
        }        
        vector<int> vec(n+m);
        int i =0,j=0,p=0;
        while(i<m && j<n && p < n+m){
            if(nums1[i]<nums2[j]){
                vec[p]=nums1[i];
                i++;
            }else{
                vec[p]=nums2[j];
                j++;                
            }
            p++;
            if(i==m && j<n){
                while(j<n){
                    vec[p] = nums2[j];
                    j++;
                    p++;
                }
            }

            if(j==n && i<m){
                while(i<m){
                    vec[p] = nums1[i];
                    i++;
                    p++;
                }
            }            
        }
        double ans = 0;

        if((n+m)%2==1){
            ans = vec[index];
            return ans;
        }else{
            ans = (vec[index] + vec[index-1])/2.0;
            return ans;
        }
    }
};
