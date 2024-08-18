class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> jewelMap;
        int sum = 0;

        // Store the count of each jewel in the jewelMap
        for(char jewel : jewels) {
            jewelMap[jewel]++;
        }

        // Count the number of jewels in the stones
        for(char stone : stones) {
            if(jewelMap.find(stone) != jewelMap.end()) {
                sum++;
            }
        }

        return sum;
    }
};