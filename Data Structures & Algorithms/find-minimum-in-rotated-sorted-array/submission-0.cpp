class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minIdx = 0;
        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1; // min is to the right
            } else {
                right = mid;    // min is at mid or to the left
            }
        }
        return nums[left];
    }
};
