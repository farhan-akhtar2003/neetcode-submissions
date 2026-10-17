class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> sc;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int top = sc.top();
                sc.pop();
                int top2 = sc.top();
                sc.pop();
                sc.push(top2);
                sc.push(top);
                sc.push(top + top2);
            } else if (operations[i] == "D") {
                sc.push(2 * sc.top());
            } else if (operations[i] == "C") {
                sc.pop();
            } else {
                sc.push(stoi(operations[i]));  // stoi --> string to int
            }
        }

        int sum = 0;
        while (!sc.empty()) {
            sum += (int)sc.top();
            sc.pop();
        }

        return sum;
    }
};