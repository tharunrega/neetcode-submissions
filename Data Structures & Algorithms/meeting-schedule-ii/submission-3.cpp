/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& vec) {
        sort(vec.begin(),vec.end(),
            [](const Interval &a,const Interval &b){
                return a.start < b.start;
            });
        
        multiset<int> st;
        for(auto v : vec){
            auto it = st.upper_bound(v.start);
            if(it != st.begin()){
                it--;
                st.erase(it);
            }
            st.insert(v.end);
        }
        return st.size();   
    }   
};


