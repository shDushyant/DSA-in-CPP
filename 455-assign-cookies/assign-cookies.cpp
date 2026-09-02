class Solution {
public:
    int cookie(vector<int>&s, int target){
       int low=0,high=s.size()-1;
       int find=-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(s[mid]>=target){
            find=s[mid];
            high=mid-1;
        } 
        else low=mid+1;
       }
       return find;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        int cnt=0;
        for(int i=0;i<g.size();i++){
            int assigned= cookie(s,g[i]);
            if(assigned!=-1){
              cnt++;
              auto it = find(s.begin(), s.end(), assigned);
              s.erase(it);
            }
        }
        return cnt;
    }
};