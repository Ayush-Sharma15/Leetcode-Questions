class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 0, j = 0, k = 0;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == searchWord[j]) {
                j++;
                if (j == searchWord.length() && k == 0) {
                    return count + 1;
                }
                continue;
            }
            if (sentence[i] == ' ') {
                count++;
                k = 0;
            } else {
                k++;
            }
            j = 0;
        }
        return -1;
    }
};
