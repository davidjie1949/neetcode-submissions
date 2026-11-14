class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int left = 0;
        // int right = heights.size() - 1;
        // int maxArea = (right - left) * std::min(left, right);
        // while (left < right) {
        //     int temp = (right - left) * std::min(left, right);
        //     if (maxArea < temp) {
        //         maxArea = temp;
        //         ++left;
        //     } else {
        //         --right;
        //     }
        // }
        // return maxArea;

        int right = 1;
        int maxArea = 0;
        
        for (int left = 0; left < heights.size(); ++left) {
            
            for (int right = left + 1; right < heights.size(); ++right) {
                int temp = (right - left) * std::min(heights[left], heights[right]);
                if (temp > maxArea) {
                    maxArea = temp;
                }

                // if (heights[left] > heights[right]) {
                //     ++left;
                // } else {
                //     ++right;
                // }
            }
        }

        return maxArea;
    }
};
