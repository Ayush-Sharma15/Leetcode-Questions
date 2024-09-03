class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        int sum = 0;
        

        for (int i = 0; i < s.length(); i++) {
            int no = s[i] - 'a' + 1;
            num += to_string(no);  
        }
        
        
        while (k > 0) {
            sum = 0;
            for (int i = 0; i < num.length(); i++) {
                sum += num[i] - '0'; 
            }
            num = to_string(sum); 
            k--;
        }
        
        return sum;
    }
};