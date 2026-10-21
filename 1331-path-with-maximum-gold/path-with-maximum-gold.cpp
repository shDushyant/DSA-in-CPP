
class Solution {
public:
    int collectGold(int i, int j, vector<vector<int>>& grid, int sum) {
        int m = grid.size();
        int n = grid[0].size();

        int temp = grid[i][j];
        sum += temp;              // collect current cell's gold
        grid[i][j] = 0;           // mark visited

        int maxGold = sum;        // base result: stop at current cell

        if (i - 1 >= 0 && grid[i - 1][j] != 0) {
            maxGold = max(maxGold,
                collectGold(i - 1, j, grid, sum));
        }

        if (i + 1 < m && grid[i + 1][j] != 0) {
            maxGold = max(maxGold,
                collectGold(i + 1, j, grid, sum));
        }

        if (j - 1 >= 0 && grid[i][j - 1] != 0) {
            maxGold = max(maxGold,
                collectGold(i, j - 1, grid, sum));
        }

        if (j + 1 < n && grid[i][j + 1] != 0) {
            maxGold = max(maxGold,
                collectGold(i, j + 1, grid, sum));
        }

        grid[i][j] = temp;        // restore cell
        return maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    int total_gold = collectGold(i, j, grid, 0);
                    max_gold = max(max_gold, total_gold);
                }
            }
        }

        return max_gold;
    }
};
