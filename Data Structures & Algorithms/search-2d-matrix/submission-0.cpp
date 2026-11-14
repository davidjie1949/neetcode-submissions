class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size() - 1;

        while (start <= end) {
            int mid_row = (start + end) / 2;
            if (matrix[mid_row].front() > target) {
                end = mid_row - 1;
            } else if (matrix[mid_row].back() < target) {
                start = mid_row + 1;
            } else {
                start = mid_row;
                break;
            }
        }
        if (start > end) return false;

        int left = 0;
        int right = matrix[0].size() - 1;
        while (left <= right) {
            int mid_col = (left + right) / 2;
            if (matrix[start][mid_col] > target) {
                right = mid_col - 1;
            } else if (matrix[start][mid_col] < target) {
                left = mid_col + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
