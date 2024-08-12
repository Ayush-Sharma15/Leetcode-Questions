class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> mp1;
        map<char, int> mp2;
        for (int i = 0; i < s.length(); ++i) {
            mp1[s[i]] = i; 
            mp2[t[i]] = i; 
        }
        int result = 0;
        for (const auto& it : mp1) { 
            result += abs(it.second - mp2[it.first]); 
        }
        return result;
    }
};