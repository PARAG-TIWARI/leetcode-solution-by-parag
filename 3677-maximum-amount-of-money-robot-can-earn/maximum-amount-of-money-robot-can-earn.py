class Solution:
    def maximumAmount(self, coins):
        m, n = len(coins), len(coins[0])
        NEG = -10**18
        
        dp = [[[NEG]*3 for _ in range(n)] for _ in range(m)]

        for k in range(3):
            if coins[0][0] >= 0:
                dp[0][0][k] = coins[0][0]
            else:
                dp[0][0][k] = 0 if k > 0 else coins[0][0]

        for i in range(m):
            for j in range(n):
                if i==0 and j==0:
                    continue

                for k in range(3):

                    best = NEG
                    if i>0:
                        best = max(best, dp[i-1][j][k])
                    if j>0:
                        best = max(best, dp[i][j-1][k])

                    if best != NEG:
                        dp[i][j][k] = max(dp[i][j][k], best + coins[i][j])

                    if coins[i][j] < 0 and k > 0:
                        best2 = NEG
                        if i>0:
                            best2 = max(best2, dp[i-1][j][k-1])
                        if j>0:
                            best2 = max(best2, dp[i][j-1][k-1])

                        if best2 != NEG:
                            dp[i][j][k] = max(dp[i][j][k], best2)

        return max(dp[m-1][n-1])