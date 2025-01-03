class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cntx1 = 0, cnty1 = 0, cntx2 = 0, cnty2 = 0;
        int n = s1.length();
        
        for (int i = 0; i < n; i++) {
            char temp1 = s1[i];
            char temp2 = s2[i];

            if (temp1 == temp2)
                continue;

            if (temp1 == 'x')
                cntx1++;
            else
                cnty1++;
            if (temp2 == 'x')
                cntx2++;
            else
                cnty2++;
        }

        if ((cntx1 + cntx2) % 2 != 0 || (cnty1 + cnty2) % 2 != 0)
            return -1;

        int ans = cntx1 / 2 + cnty1 / 2 + (cnty2 % 2) * 2;
        return ans;
    }
};
