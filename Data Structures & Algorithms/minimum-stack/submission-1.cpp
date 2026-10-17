// Work for some case but its wrong bcz sc.push(minm) is storing duplicate minm even though that
// minm ele is appeared only 1 time may be so need per push tracking and minimum till far. class
// MinStack {
//    public:
//     int minm = INT_MAX;
//     deque<int> dq;
//     stack<int> sc;
//     MinStack() {}

//     void push(int val) {
//         dq.push_front(val);
//         minm = min(minm, val);
//         sc.push(minm);
//     }

//     void pop() {
//         int ele = dq.front();
//         dq.pop_front();
//         if (sc.top() == ele) sc.pop();
//         minm = sc.empty() ? INT_MAX : sc.top();
//     }

//     int top() { return dq.front(); }

//     int getMin() { return sc.top(); }
// };

class MinStack {
   public:
    stack<pair<int, int>> sc; // store ele in stack and minm till yet 

    MinStack() {}

    void push(int val) {
        int minm_till_yet = sc.empty() ? val : min(val, sc.top().second);
        sc.push({val, minm_till_yet});
    }

    void pop() { sc.pop(); }

    int top() { return sc.top().first; }

    int getMin() { return sc.top().second; }
};
