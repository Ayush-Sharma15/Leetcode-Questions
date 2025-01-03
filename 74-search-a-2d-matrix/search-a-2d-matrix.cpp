class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , start = 0 , end = n-1 , mid;
        while( start <= end ){
            mid = start + (end - start) / 2;
            int m = matrix[mid].size();
            if(target >= matrix[mid][0] and target <= matrix[mid][m-1]){
                int s1 = 0 , e1 = m -1 , m1 ;
                while(s1 <= e1 ){
                    m1 = s1 + (e1-s1) / 2 ;
                    if(matrix[mid][m1] == target)
                    return true;
                    else if(target > matrix[mid][m1] )
                    s1 = m1+1;
                    else
                    e1 = m1 - 1;
                }
                return false;
            }
            else if(target > matrix[mid][m-1])
            start = mid + 1;
            else
            end = mid -1 ;
        }
        return false;
    }
};