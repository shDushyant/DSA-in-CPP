class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int freetime=intervals[0][1];
        int cnt=1;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=freetime){
                cnt++;
                freetime=intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};