class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int >ans;  
        for(int i=left;i<=right;i++){
            int temp=i;
            while(temp>0){
                int ld=temp%10;
                if(ld==0 || i%ld!=0) break;
                temp/=10;
            }
            if(temp==0) ans.push_back(i);
        }
            
        return ans;
    }
};