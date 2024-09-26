class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        
        # Create a 2D DP table
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        
        # Empty pattern matches empty string
        dp[0][0] = True
        
        # Handle patterns with *
        for j in range(1, n + 1):
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-2]
        
        # Fill the DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j-1] == '*':
                    dp[i][j] = dp[i][j-2]
                    if p[j-2] == '.' or p[j-2] == s[i-1]:
                        dp[i][j] |= dp[i-1][j]
                elif p[j-1] == '.' or p[j-1] == s[i-1]:
                    dp[i][j] = dp[i-1][j-1]
        
        return dp[m][n]