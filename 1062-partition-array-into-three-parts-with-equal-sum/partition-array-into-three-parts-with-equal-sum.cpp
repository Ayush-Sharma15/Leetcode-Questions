class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
      int sum = accumulate(arr.begin(), arr.end(), 0);
      if(sum%3!=0)
      return false;
      int check = sum/3;
      int temp = 0;
      int ctr = 0;
      for (int i = 0;i<arr.size();i++)
      {
        temp += arr[i];
        if (temp == check){
            temp = 0;
            ctr +=1;
        }
        }
      
      if (ctr >= 3){
        return true;
      }
      else{
        return false;
      }
    }
};