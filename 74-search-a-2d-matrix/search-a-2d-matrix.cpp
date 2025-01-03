class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), start = 0, end = n - 1, mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            int m = matrix[mid].size();

            if (target >= matrix[mid][0] && target <= matrix[mid][m - 1]) {
                int left = 0, right = m - 1;
                while (left <= right) {
                    int midCol = left + (right - left) / 2;
                    if (matrix[mid][midCol] == target)
                        return true;
                    else if (matrix[mid][midCol] < target)
                        left = midCol + 1;
                    else
                        right = midCol - 1;
                }
                return false;
            } 
            else if (target > matrix[mid][m - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};
