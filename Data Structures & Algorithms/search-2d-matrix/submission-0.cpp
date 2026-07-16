class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0, hi = n-1;
        int row = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(matrix[mid][0]==target) return true;    
            else if(matrix[mid][0]<target){
                lo = mid+1;
                row = mid;
            }else{
                hi = mid-1;
            }
        }
        if(row == -1) return false;
        int lo_col = 0,hi_col = m-1;

        while(lo_col<=hi_col){
            int mid_col = (lo_col+hi_col)/2;
            if(matrix[row][mid_col]==target) return true;
            else if(matrix[row][mid_col]<target){
                lo_col = mid_col+1;
            }else{
                hi_col = mid_col-1;
            }
        }
        return false;

    }
};
