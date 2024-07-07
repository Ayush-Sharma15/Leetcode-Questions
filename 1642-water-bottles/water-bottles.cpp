class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int t=numBottles,r=numBottles/numExchange,e=0;
        
         e=numBottles-(numExchange*r);
         if(r+e<numExchange)
         return t+r;
          r=r+e;
          if(numBottles==numExchange)
          return numBottles+1;
        while(r>=numExchange)
        {
            r=numBottles/numExchange;
            t=t+r;
            e=numBottles-(numExchange*r);
            r=r+e;
            numBottles=r;
                    }

        return t;
    }
};