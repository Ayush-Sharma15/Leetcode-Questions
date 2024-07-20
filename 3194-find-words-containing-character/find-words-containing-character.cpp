class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for(int i=0;i<words.size();i++){
            auto it = find(words[i].begin(), words[i].end(), x);
            if (it != words[i].end())
            result.push_back(i);
        }
        return result;
    }
};