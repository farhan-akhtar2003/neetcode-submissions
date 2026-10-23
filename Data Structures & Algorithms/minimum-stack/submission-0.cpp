class MinStack {
   public:
    int minm = INT_MAX;
    deque<int> dq;
    stack<int> sc;
    MinStack() {}

    void push(int val) {
        dq.push_front(val);
        minm = min(minm, val);
        sc.push(minm);
    }

    void pop() {
        int ele = dq.front();
        dq.pop_front();
        if (sc.top() == ele) sc.pop();
        minm = sc.empty() ? INT_MAX : sc.top();
    }

    int top() { return dq.front(); }

    int getMin() { return sc.top(); }
};
