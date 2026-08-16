/*class Solution {
public:
    long sum(vector<int>&stones){
        int add_sum=0;
        for(int x:stones){
            add_sum+=x;
        }
        return add_sum;
    }
    bool stoneGameIX(vector<int>& stones) {
        if(stones.size()==1) return false;
        if(stones.size()%2==1){                 // odd case
            if(sum(stones)%3==0) return false;
            else return true;
        }
        else{                          //even case
            if(sum(stones)%3==0) return true;
            else return false;
        }
        return false;
    }
}; */
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If the number of remainder-0 stones is even,
        // Alice wins if both remainder-1 and remainder-2 exist.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If remainder-0 stones are odd, one side must
        // have at least 2 more stones than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};