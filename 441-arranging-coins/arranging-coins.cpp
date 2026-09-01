class Solution {
public:
    int arrangeCoins(int n) {
        /*int rows=0;         brute force with O(N);
        for(int i=1;i<=n;i++){
          if(i<=n) {
            n-=i;
          rows++;
          }
          else break;
        }
        return rows;*/
        return floor(-0.5+sqrt((double)2*n+0.25));
    }
};