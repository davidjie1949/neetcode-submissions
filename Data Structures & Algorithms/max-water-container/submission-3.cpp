class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int temp = (right - left) * std::min(heights[left], heights[right]);
            if (maxArea < temp) {
                maxArea = temp;
            }

            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;

        // Brute Force
        // int maxArea = 0;
        // for (int left = 0; left < heights.size(); ++left) {
        //     for (int right = left + 1; right < heights.size(); ++right) {
        //         int temp = (right - left) * std::min(heights[left], heights[right]);
        //         if (temp > maxArea) {
        //             maxArea = temp;
        //         }
        //     }
        // }
        // return maxArea;
    }
};
