class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray = mergeTwoSortedArray(nums1, nums2);
        int n = mergedArray.size();

        if (n % 2 == 0) {
            return (mergedArray[(n - 1) / 2] + mergedArray[n/2]) * 0.5;
        } else {
            return mergedArray[n/2];
        }
    }

    vector<int> mergeTwoSortedArray(vector<int>& A, vector<int>& B) {
        vector<int> merged;
        merged.reserve(A.size() + B.size());
        int i = 0, j = 0;

        while ( i < A.size() && j < B.size()) {
            merged.push_back((A[i] < B[j]) ? A[i++] : B[j++]);
        }

        while (i < A.size()) {
            merged.push_back(A[i++]);
        }

        while (j < B.size()) {
            merged.push_back(B[j++]);
        }
        return merged;
    }
};
