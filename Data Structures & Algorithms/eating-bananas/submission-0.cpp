class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = (left + right) / 2;
            long count = 0;
            for (int pile : piles) count += (pile + mid - 1) / mid; // ceil
            if (count <= h)
                right = mid;     // feasible, try smaller
            else
                left = mid + 1;  // too slow, go bigger
        }   

        return left;
    }
};
