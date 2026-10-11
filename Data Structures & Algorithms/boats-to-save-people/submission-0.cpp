class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i = 0, j = n - 1;
        sort(people.begin(), people.end());

        int cnt = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                cnt++;
                i++;
                j--;
            } else {
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};