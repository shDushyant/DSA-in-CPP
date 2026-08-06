class Solution {
public:
    int smallestNumber(int n, int t) {
        /*int low=n;
        int high= 2*n;
        int ans=1;
        while(low<=high){
            int pdt=1;
            int mid= low+(high-low)/2;
            while(mid>0){
                int ld= mid%10;
                pdt *=ld;
                mid/=10;
            }
            if(pdt%t==0) {
             ans=mid;
             high=mid-1;
            }
            else  high=mid-1;
            
        }
        return ans;*/
        int temp=n;
        int pdt=1;
        while(n>0){
            int ld=n%10;
            pdt=pdt*ld;
            n/=10;
        }
        if(pdt%t==0) return temp;
        else return smallestNumber(temp+1,t);
        
        
    }
};