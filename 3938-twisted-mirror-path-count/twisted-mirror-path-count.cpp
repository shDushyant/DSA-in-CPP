#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> A(m, vector<int>(n, 0)); // arrived moving right
        vector<vector<int>> D(m, vector<int>(n, 0)); // arrived moving down

        // start cell is empty: treat as one arrival
        // push its two attempts directly
        // right attempt -> into (0,1) moving right
        if (n > 1) A[0][1] = 1;
        // down attempt -> into (1,0) moving down
        if (m > 1) D[1][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                if (grid[i][j] == 0) {
                    int tot = (A[i][j] + D[i][j]) % MOD;
                    if (i == m - 1 && j == n - 1) return tot;
                    if (!tot) continue;
                    if (j + 1 < n) A[i][j + 1] = (A[i][j + 1] + tot) % MOD;
                    if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + tot) % MOD;
                } else {
                    // mirror: arrived moving right -> turned down
                    if (A[i][j] && i + 1 < m)
                        D[i + 1][j] = (D[i + 1][j] + A[i][j]) % MOD;
                    // mirror: arrived moving down -> turned right
                    if (D[i][j] && j + 1 < n)
                        A[i][j + 1] = (A[i][j + 1] + D[i][j]) % MOD;
                }
            }
        }
        return 0;
    }
};