class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> leftCount(26, 0); 
        vector<int> rightCount(26, 0); 
        for (char c : s) {
            rightCount[c - 'a']++;
        }
        
        unordered_set<string> uniquePalindromes; 
        for (int i = 0; i < n; ++i) {
            char middleChar = s[i];
            int middleIndex = middleChar - 'a';
            
            rightCount[middleIndex]--;
            
            for (int c = 0; c < 26; ++c) {
                if (leftCount[c] > 0 && rightCount[c] > 0) {
                    string palindrome = string(1, c + 'a') + middleChar + string(1, c + 'a');
                    uniquePalindromes.insert(palindrome);
                }
            }
            
            leftCount[middleIndex]++;
        }
        
        return uniquePalindromes.size();
    }
};
