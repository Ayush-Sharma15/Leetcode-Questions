class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            bool divide=true;
            int temp=i;
            while(temp>0){
                
                int rem=temp%10;
                if(rem==0 or i%rem!=0){
                    divide=false;
                    break;
                }
                temp=temp/10;
            }
            if(divide)
                ans.push_back(i);
        }
        return ans;
    }
};