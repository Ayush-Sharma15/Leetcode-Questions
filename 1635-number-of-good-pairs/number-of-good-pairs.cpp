class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map <int, int> map;

        for(int i : nums)
            map[i]++;

        int pair = 0;
        for(auto i : map)
        {
            if(i.second > 1)
                pair += (i.second * (i.second - 1))/2;
        }
        return pair;
    }
};