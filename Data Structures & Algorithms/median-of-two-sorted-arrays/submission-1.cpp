class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lenA = nums1.size(), lenB = nums2.size();
        if (lenA > lenB) { return findMedianSortedArrays(nums2, nums1);}
        int len = lenA + lenB;
        int A_startK = 0, A_endK = lenA;
        int cutA, cutB;

        while (A_startK <= A_endK) {
            cutA = (A_endK + A_startK) / 2;
            cutB = (len + 1) / 2 - cutA;

            double L1 = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
            double L2 = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
            double R1 = (cutA == lenA) ? INT_MAX : nums1[cutA];
            double R2 = (cutB == lenB) ? INT_MAX : nums2[cutB];

            if (L1 > R2) {A_endK = cutA - 1;}
            else if (R1 < L2) {A_startK = cutA + 1;}
            else {
                if (len % 2 == 0) {
                    return (std::max(L1,L2) + std::min(R1,R2)) / 2;
                } else {
                    return std::max(L1, L2);
                }
            }
        }
        return -1;
    }
};
