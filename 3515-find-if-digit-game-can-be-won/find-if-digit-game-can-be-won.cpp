class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1=0,sum2=0;
        for(auto x: nums){
            if(x>=10)
            sum1+=x;
            else
            sum2+=x;
        }
        if(sum1>sum2 or sum2>sum1)
        return true;
        return false;
    }
};