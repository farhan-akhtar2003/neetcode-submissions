class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();

        int l = 0;
        priority_queue<pair<int, int>> pq;

        for (int r = 0; r < n; r++) {
            // add ele
            pq.push({abs(arr[r] - x), arr[r]});

            // shrink window for invalid ele aka we need only K min ele
            while (pq.size() > k) {
                pq.pop();
                l++;
            }
        }

        // update ans
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};