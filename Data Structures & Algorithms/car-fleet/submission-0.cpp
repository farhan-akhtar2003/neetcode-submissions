/*
1. Pair each car's position and speed; sort cars by position decreasing.
2. Calculate each car's arrival time.
3. If arrival time exceeds fleet ahead's time, car forms new fleet; otherwise, it joins fleet ahead.
4. Stack size gives total final fleet count.
TC: O(nlog n), SC: O(n)
*/
const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vec;
        int n = position.size();
        stack<int> timeStack;

        for (int i = 0; i < n; i++) {
            vec.push_back({position[i], speed[i]});
        }

        sort(vec.begin(), vec.end(), [](auto& x, auto& y) { return x.first > y.first; });

        for (int i = 0; i < n; i++) {
            double time = (double)(target - vec[i].first) / vec[i].second;

            if (timeStack.empty() || time > timeStack.top()) timeStack.push(time);
        }

        return timeStack.size();
    }
};
