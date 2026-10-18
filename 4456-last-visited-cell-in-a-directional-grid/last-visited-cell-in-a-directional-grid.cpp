class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        set<pair<int,int>>stt;
        stack<pair<int,int>>st;
        int i=0,j=0;
        while(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()){
             if (stt.count({i, j})) {
                break;
            }
            stt.insert({i,j});
            st.push({i,j});
            if(grid[i][j]=='R') j++;
            else if(grid[i][j]=='L') j--;
            else if(grid[i][j]=='U') i--;
            else if(grid[i][j]=='D') i++;
        }
        if(!st.empty()) return {st.top().first,st.top().second};
        return {-1,-1};        
            
    }
};