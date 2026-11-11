class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       //long long way1= cost1*need1 + cost2*need2;
       //long long way2= max(need1,need2)*costBoth;
       long long need= min(need1,need2);
       long long cost=0;
       cost+= need*(min(1LL*cost1+cost2,1LL*costBoth));
       need1= (need1-need);
       need2= (need2-need);
       cost+= 1LL*need1*min(cost1,costBoth);
       cost+=1LL* need2*min(cost2,costBoth);
       return cost;
    }
};