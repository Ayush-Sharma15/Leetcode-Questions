class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int count=0,rows=grid.size(),cols=grid[0].size();
        if(rows==0) 
        return 0;
        for(int i=0;i<cols;i++){
            for(int j=1;j<rows;j++){
                if(grid[j][i]<=grid[j-1][i]){
                count+=(grid[j-1][i]+1)-grid[j][i];
                grid[j][i]=grid[j-1][i]+1;}
            }
        }
        return count;
    }
};