class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int total=0;
        for(char c:s){
            if(cnt<0){
                total+= abs(cnt);
                cnt=0;
            }
            if(c=='(') cnt++;
            else cnt--;
        }
        return total+ abs(cnt);
    }
};