class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 0; 
        int n = searchWord.length(); 
        stringstream ss(sentence);
        string word;
        
        while (ss >> word) {
            count++;
            if (word.substr(0, n) == searchWord) {
                return count;
            }
        }
        
        return -1;
    }
};