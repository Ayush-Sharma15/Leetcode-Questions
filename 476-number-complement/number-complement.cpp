class Solution {
public:
    int findComplement(int num) {
        string s = "", ans = "";
        
        while(num > 0) {
            int rem = num % 2;
            s = to_string(rem) + s;
            num = num / 2;
        }
        
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '1')
                ans += '0';
            else
                ans += '1';
        }
        
        int complement = 0;
        for(int i = 0; i < ans.length(); i++) {
            complement = complement * 2 + (ans[i] - '0');
        }
        
        return complement;
    }
};
