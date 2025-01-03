class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long n = nums.size() , res=0;

        vector<long long int> ps(n);
        ps[0] = nums[0];
        for(int i = 1 ; i < n ; i++)
        ps[i] = ps[i-1] + nums[i];
        
        for(int i = 1 ; i < n  ; i++){
            if( ps[i-1] >= (ps[n-1] - ps[i-1]))
                res++;
        
        }
        return res;

    }
};