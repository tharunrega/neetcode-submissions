class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n = nums.size();

        int head = -1, tail = 0;
        vector<int> ans;

        while (head + 1 < n) {

            while (head + 1 < n && head - tail + 1 < k) {
                 head++;
                pq.push({nums[head], head});
            }

            while (!pq.empty() && pq.top().second < tail)
                pq.pop();

            if (head - tail + 1 == k)
                ans.push_back(pq.top().first);

            if (tail <= head) {
                tail++;
            } else {
                tail++;
                head = tail - 1;
            }
        }

        return ans;
    }
};