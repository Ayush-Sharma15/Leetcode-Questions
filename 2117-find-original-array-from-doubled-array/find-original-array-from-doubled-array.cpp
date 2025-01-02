class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) 
            return {}; 

        map<int, int> mp;
        for (int num : changed) 
            mp[num]++;

        vector<int> original;

        for (auto &[key, count] : mp) {
            if (mp[(long long)key * 2] < count) 
                return {};

            if (key == 0) {
                if (count % 2 != 0) 
                    return {};
                original.insert(original.end(), count / 2, 0);
            } else {
                original.insert(original.end(), count, key);
                mp[(long long)key * 2] -= count;
            }
        }
        return original;
    }
};
