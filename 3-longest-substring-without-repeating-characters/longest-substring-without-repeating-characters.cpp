class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[255];
        fill(arr, arr + 255, -1);
        int left = 0 , right = 0 , len = 0 , maxlen = 0 ;
        int n = s.length();
        if(n==1) return 1;
        while(right < n){
            if(arr[s[right]] != -1){
                if(arr[s[right]] >= left){
                    left = arr[s[right]] +1;
                }
            }
            len = right - left +1;
            maxlen = max(len,maxlen);
            arr[s[right]] = right;
            right++;
        }
        return maxlen;
    }
};