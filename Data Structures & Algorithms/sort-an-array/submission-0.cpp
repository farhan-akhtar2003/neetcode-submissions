class Solution {
   public:
    void merge(int l, int mid, int h, vector<int>& nums) {
        vector<int> left, right;

        // Fill left half [l..mid]
        for (int i = l; i <= mid; i++) {
            left.push_back(nums[i]);
        }
        // Fill right half [mid+1..h]
        for (int i = mid + 1; i <= h; i++) {
            right.push_back(nums[i]);
        }

        int i = 0, j = 0;
        int k = l;

        // Merge both sorted halves
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }

        // Remaining elements of left
        while (i < left.size()) {
            nums[k++] = left[i++];
        }
        // Remaining elements of right
        while (j < right.size()) {
            nums[k++] = right[j++];
        }
    }

    void mergeSort(int l, int h, vector<int>& nums) {
        // Note that a single ele is always sorted
        if (l >= h) return;
        int mid = l + (h - l) / 2;

        // Trust the method that it will return sorted array
        mergeSort(l, mid, nums);      // 1st half
        mergeSort(mid + 1, h, nums);  // 2nd half
        merge(l, mid, h, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};