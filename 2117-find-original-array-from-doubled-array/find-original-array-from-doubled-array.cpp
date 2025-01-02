#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) 
            return {}; 
        unordered_map<int, int> mp;
        for (int num : changed) {
            mp[num]++;
        }

        sort(changed.begin(), changed.end());
        
        vector<int> original;

        for (int num : changed) {
            if (mp[num] == 0) 
                continue; 
            if (mp[num * 2] > 0) {
                original.push_back(num);
                mp[num]--;  
                mp[num * 2]--; 
            } else {
                return {}; 
            }
        }

        return original;
    }
};
