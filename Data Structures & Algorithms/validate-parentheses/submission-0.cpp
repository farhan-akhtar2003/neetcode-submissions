class Solution {
   public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> sc;

        if (n % 2 != 0) return false;

        for (int i = 0; i < n / 2; i++) {
            sc.push(s[i]);
        }
        for (int i = n / 2; i < n; i++) {
            char c = sc.top();
            if (c == '{' && s[i] != '}') return false;
            if (c == '[' && s[i] != ']') return false;
            if (c == '(' && s[i] != ')') return false;
            sc.pop();
        }
        return true;
    }
};
