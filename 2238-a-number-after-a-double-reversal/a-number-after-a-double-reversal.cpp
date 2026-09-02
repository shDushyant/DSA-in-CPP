class Solution {
public:
    bool isSameAfterReversals(int num) {
        int temp=num;
        if(temp>=0 && temp<=9) return true;
        if(temp%10==0) return false;
        return true;
    }
};