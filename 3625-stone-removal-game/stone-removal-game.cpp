class Solution {
public:
    bool canAliceWin(int n) {
     if(n<10) return false;
    for(int i=10;i>=1;i--){
        if(n<i && i%2==0) return false;
        if(n<i) break;
        n=n-i;
        //if(n<i&& i%2!=0) return true;
    }
     return true;
    
}
};