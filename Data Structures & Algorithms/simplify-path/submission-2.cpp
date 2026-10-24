const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
   public:
    // TC: O(n) SC: O(n)
    string simplifyPath(string path) {
        string ans = "";
        int n = path.size();
        stack<string> st;

        string lastWord = "";
        string dots = "";

        for (int i = 0; i <= n; i++) {
            char ch = (i == n ? '/' : path[i]);

            if (ch != '/') {
                lastWord += ch;
            } else {
                if (lastWord == "..") {
                    if (!st.empty()) st.pop();
                } else if (lastWord != "" &&
                           lastWord != ".") {  // not null and . is present may be next time it
                                               // forms .. and we need poping the last directory
                    st.push(lastWord);
                }

                lastWord = "";
            }
        }

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};