const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class FreqStack {
   public:
    unordered_map<int, stack<int>> indices;
    unordered_map<int, int> freq;
    int i = 0;

    FreqStack() {}

    void push(int val) {
        indices[val].push(i++);
        freq[val]++;
    }

    int pop() {
        int bestVal = 0;
        int bestFreq = 0;
        int bestIndex = -1;

        for (auto& [val, f] : freq) {
            if (f > bestFreq || (f == bestFreq && indices[val].top() > bestIndex)) {
                bestFreq = f;
                bestIndex = indices[val].top();
                bestVal = val;
            }
        }

        indices[bestVal].pop();
        freq[bestVal]--;

        if (freq[bestVal] == 0) freq.erase(bestVal);
        return bestVal;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */