class Solution {
public:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // If land touches the boundary, the island is not closed
        if (r < 0 || c < 0 || r >= m || c >= n)
            return false;

        // Water or already visited
        if (grid[r][c] == 1)
            return true;

        // Mark land as visited
        grid[r][c] = 1;

        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid))
                        cnt++;
                }
            }
        }

        return cnt;
    }
};