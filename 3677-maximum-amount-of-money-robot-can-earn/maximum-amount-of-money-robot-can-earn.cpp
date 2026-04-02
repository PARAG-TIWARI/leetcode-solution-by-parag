class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        
        const long long NEG = -1e18;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, NEG)));

        for(int k=0;k<3;k++){
            if(coins[0][0] >= 0) dp[0][0][k] = coins[0][0];
            else{
                if(k>0) dp[0][0][k] = 0;
                else dp[0][0][k] = coins[0][0];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                for(int k=0;k<3;k++){

                    long long best = NEG;

                    if(i>0) best = max(best, dp[i-1][j][k]);
                    if(j>0) best = max(best, dp[i][j-1][k]);

                    if(best!=NEG)
                        dp[i][j][k] = max(dp[i][j][k], best + coins[i][j]);

                    if(coins[i][j] < 0 && k>0){
                        long long best2 = NEG;

                        if(i>0) best2 = max(best2, dp[i-1][j][k-1]);
                        if(j>0) best2 = max(best2, dp[i][j-1][k-1]);

                        if(best2!=NEG)
                            dp[i][j][k] = max(dp[i][j][k], best2);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};