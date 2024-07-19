class Solution {
public:
    int neg_num(vector<int>& mat) {
        int up = mat.size() - 1, lb = 0, mid;
        while (lb <= up) {
            mid = lb + (up - lb) / 2;
            if (mat[mid] < 0)
                up = mid - 1; // If mid is negative, move the upper bound down
            else
                lb = mid + 1; // If mid is non-negative, move the lower bound up
        }
        // After the loop, lb is the first index where the element is negative
        return mat.size() - lb;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            sum += neg_num(grid[i]);
        }
        return sum;
    }
};
