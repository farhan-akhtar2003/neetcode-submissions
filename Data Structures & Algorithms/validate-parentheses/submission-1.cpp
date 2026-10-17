class Solution {
   public:
    bool isValid(string s) {
        stack<char> sc;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                sc.push(c);
            } else {
                if (sc.empty()) return false;
                char top = sc.top();

                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
                sc.pop();
            }
        }

        return sc.empty();
    }
};