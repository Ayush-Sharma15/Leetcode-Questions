class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        int row = 0, col = cols - 1;
        
        // Start from the top-right corner of the grid
        while (row < rows && col >= 0) {
            if (grid[row][col] < 0) {
                // If the current element is negative, all elements below in the same column are also negative
                count += (rows - row);
                col--; // Move left in the same row
            } else {
                // If the current element is non-negative, move down to the next row
                row++;
            }
        }
        
        return count;
    }
};
