class Solution {
public:
    string largestOddNumber(string num) {
        int idx=-1;
        int temp=num[num.size()-1];
        if(temp%2==1) return num;
        else{
        for(int i=num.size()-1;i>=0;i--){
            if(num[i]%2!=0) {idx=i; break;}
        }
        }
        string ans="";
        if(idx==-1) return ans;
        for(int i=0;i<=idx;i++){
           ans.push_back(num[i]);
        }
        return ans;
        
    }
};