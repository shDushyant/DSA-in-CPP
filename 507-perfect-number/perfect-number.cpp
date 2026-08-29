class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        int sum=1;
        int temp=num;
        for(int i=2;i*i<=temp;i++){
            if(temp%i==0) sum+=(i+(num/i));
        }
        if(sum==num) return true;
        else return false;
    }
};