class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> times(n,{0,0});
        int ans = 0;
        for(int i=0;i<n;i++){
            times[i].first = position[i];
            times[i].second = 1.0 * (target - position[i]) / speed[i];  
        }

        sort(times.begin(),times.end(),greater<pair<int,double>>());

        double cur_time = 0;

        for(int i = 0;i<n;i++){
            if(cur_time < times[i].second){
                ans++;
                cur_time = times[i].second;
            }
        }
        return ans;
    }
};
