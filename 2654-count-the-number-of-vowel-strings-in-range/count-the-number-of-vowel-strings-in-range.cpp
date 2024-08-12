class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count=0;
        string s;
        for(int i=left;i<=right;i++){
            s=words[i];
            int n=s.length()-1;
            if((s[0]=='a' || s[0]=='i' || s[0]=='o' || s[0]=='u' || s[0]=='e') &&
                (s[n]=='a' || s[n]=='i' || s[n]=='o' || s[n]=='u' || s[n]=='e')){
            count++;}
        }
        return count;
    }
};