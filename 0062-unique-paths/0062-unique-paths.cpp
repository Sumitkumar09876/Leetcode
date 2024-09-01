class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D array for memoization and initialize with -1
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return findPaths(0, 0, m, n, memo);
    }

private:
    int findPaths(int i, int j, int m, int n, vector<vector<int>>& memo) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        memo[i][j] = findPaths(i + 1, j, m, n, memo) + findPaths(i, j + 1, m, n, memo);
        return memo[i][j];
    }
};