class Solution {
public:
    int countCommas(int n) {
        int commas=0;
        for(int i=1;i<=n;i++){
        int cnt=0;
        int temp=i;
        while(temp>0){
            int ld=temp%10;
            cnt++;
            if(cnt%4==0) commas++;
            temp/=10;
        }
        }
        return commas;
    }
};