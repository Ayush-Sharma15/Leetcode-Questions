// S1. Brute Force (Exhaustive Search)
// O(n^2) time, O(1) extra space
class Solution1 {
public:
    int maxScore(string s) {
        int n = s.size();
        int maxscore = 0;
        for(int i = 1; i < n; i++) {
            int score = 0;
            for(int j = 0; j < i; j++) {
                if(s[j] == '0') score++;
            }
            for(int j = i; j < n; j++) {
                if(s[j] == '1') score++;
            }
            maxscore = max(maxscore, score);
        }
        return maxscore;
    }
};

// S2. Exhaustive Search with Prefix Sum
// O(n + n) time, O(n) extra space
class Solution2 {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zerosOnLeft(n);
        zerosOnLeft[0] = (s[0] == '0');
        for(int i = 1; i < n; i++) {
            zerosOnLeft[i] = zerosOnLeft[i-1] + (s[i] == '0');
        }

        vector<int> onesOnRight(n);
        onesOnRight[n-1] = (s[n-1] == '1');
        for(int i = n-2; i >= 0; i--) {
            onesOnRight[i] = onesOnRight[i+1] + (s[i] == '1');
        }

        int maxscore = 0;
        for(int i = 1; i < n; i++) {
            int score = 0;
            score += zerosOnLeft[i-1];
            score += onesOnRight[i];
            maxscore = max(maxscore, score);
        }
        return maxscore;
    }
};

// S3. Exhaustive Search with Prefix Sum
// O(n + n) time, O(1) extra space
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int onesOnRight = (s[n-1] == '1');
        for(int i = n-2; i >= 0; i--) {
            onesOnRight += (s[i] == '1');
        }

        int maxscore = 0;
        int zerosOnLeft = (s[0] == '0'); // zerosOnLeft[0]
        for(int i = 1; i < n; i++) {
            int score = 0;
            score += zerosOnLeft;

            onesOnRight -= (s[i-1] == '1');
            score += onesOnRight;
            maxscore = max(maxscore, score);

            zerosOnLeft += (s[i] == '0');
        }
        return maxscore;
    }
};