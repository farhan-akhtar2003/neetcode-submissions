class Solution {
   public:
    // =========================================APPROACH========================================
    // Constraints: strs[i] contains only lowercase English letters → only 26 possible chars.
    //
    // 1. Create frequency array of size 26 for each string kind of count sort.
    // 2. Anagrams have same frequency array.
    // 3. Convert frequency array into string → use it as unordered_map key.
    // 4. Store strings having same key together.
    //
    // Why string key?
    // unordered_map cannot directly use vector<int> without custom hash.
    // String gives us simple STL + average O(1) hashmap lookup.
    //
    // TC: O(n * k)
    //     Frequency count → O(k)
    //     Creating 26-size key → O(26) → O(1)
    //     unordered_map → O(1) average
    //     Total → O(n * k)
    //
    // SC: O(n * k)
    //     Map stores all strings → O(n * k)
    //     Keys contain only 26 counts → O(n)
    //     ans stores all strings → O(n * k)
    //     Total → O(n * k)
    //
    // Compared to old approach:
    // map<vector<int>, vector<string>>
    // → O(n * k * log n)
    //
    // New approach:
    // unordered_map<string, vector<string>>
    // → O(n * k) average
    //
    // =======================================END OF APPROACH=====================================

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for (auto st : strs) {
            vector<int> v(26, 0);
            for (auto x : st) {
                v[x - 'a']++; // count individual alphabets frequency
            }

            string key;
            for (auto x : v) key += to_string(x) + "#"; // TC : O(26)
        
            mp[key].push_back(st);
        }

        for (auto it : mp) ans.push_back(it.second);
        return ans;
    }
};