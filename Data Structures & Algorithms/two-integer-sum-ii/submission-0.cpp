class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        int i=0,j=n-1;
        vector<int> arr;
        while(i<j){
            if(a[i]+a[j]==target){
                arr.push_back(i+1);
                arr.push_back(j+1);
                break;
            }

            else if(a[i]+a[j]<target){
                i++;
            }
            else if(a[i]+a[j]>target){
                j--;
            }
        }

        return arr;
    }
};
