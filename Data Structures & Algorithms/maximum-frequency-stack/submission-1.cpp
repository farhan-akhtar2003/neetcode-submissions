const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// TC: push O(log u), pop O(log u) || SC: O(n)
class FreqStack {
   public:
    /*
 =========================================APPROACH 2=======================================
 1. Maintain frequency of each value using freq map.
 2. Store each value's insertion indices in a stack.
 3. Maintain ordered set of {frequency, latest insertion index, value}.
 4. On push, remove old set entry, update frequency and index stack, then insert updated entry.
 5. On pop, remove set's largest entry → highest frequency wins; ties → latest insertion index wins.
 6. Decrease frequency and reinsert value if frequency > 0.
 7. TC: O(log(n)) per push/pop; SC: O(n).
 ====================================END OF APPROACH=====================================
 */
    set<tuple<int, int, int>> st;            // {frequency, latest insertion index, value}
    unordered_map<int, stack<int>> indices;  // ele --> stack of all index
    unordered_map<int, int> freq;            // ele or val --> freq
    int i = 0;

    FreqStack() {}

    void push(int val) {
        if (freq[val] > 0) {
            st.erase({freq[val], indices[val].top(), val});
        }

        indices[val].push(i++);
        freq[val]++;

        st.insert({freq[val], indices[val].top(), val});
    }

    int pop() {
        auto it = prev(st.end());
        auto [f, idx, val] = *it;
        st.erase(it);

        indices[val].pop();
        freq[val]--;

        if (freq[val] > 0) {
            st.insert({freq[val], indices[val].top(), val});
        }

        return val;
    }
};

// 1st approach: TC: push O(1), pop O(u) u = distinct active values SC: O(n).
class FreqStack1 {
   public:
    unordered_map<int, stack<int>> indices;
    unordered_map<int, int> freq;
    int i = 0;

    FreqStack1() {}

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