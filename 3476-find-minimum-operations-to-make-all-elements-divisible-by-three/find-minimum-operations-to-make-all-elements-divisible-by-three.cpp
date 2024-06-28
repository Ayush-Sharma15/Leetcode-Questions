class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int c=0;
        for(auto x:nums){
            if(x%3==0)
            continue;
            else
            c+=1;
        }
        return c;
    }
};