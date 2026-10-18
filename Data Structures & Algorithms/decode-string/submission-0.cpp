class Solution {
   public:
    // TC: O(n+m), m = decoded characters length
    // SC: O(n+m)
    string decodeString(string s) {
        int n = s.size();
        stack<string> st;   // to store strings final
        stack<int> counts;  // counting all numeric

        st.push("");
        int lastNumber = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                lastNumber =
                    lastNumber * 10 + (ch - '0');  // "300[a]" → 3 → 30 → 300 handles multiple
                                                   // digits so do not use stoi here
            } else if (ch == '[') {
                counts.push(lastNumber);
                st.push("");
                lastNumber = 0;
            } else if (ch == ']') {
                string currString = st.top();
                int num = counts.top();
                st.pop();
                counts.pop();

                string repeatedString = "";
                while (num--) repeatedString += currString;

                string prevString = st.top();
                st.pop();
                st.push(prevString + repeatedString);
            } else {
                string currString = st.top();
                st.pop();
                currString += ch;
                st.push(currString);
            }
        }

        return st.top();
    }
};