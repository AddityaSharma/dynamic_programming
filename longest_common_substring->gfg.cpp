// modified the tabulated code from the LCS problem.
    
    // the answer i.e the value of longest common substring will not be at dp[n][m], but
    // will be stored somewhere in dp, so later we traverse the complete dp matrix to find 
    // maximum value.
    
    // tabulation code:
    int longestCommonSubstr (string s1, string s2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case: 
        for(int j = 0; j < m; j++) dp[0][j] = 0;
        for(int i = 0; i < n; i++) dp[i][0] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
            }
        }
        
        int maxi = 0;
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                maxi = max(maxi, dp[i][j]);
            }
        }
        
        return maxi;
    }
    
    // space-optimised code:
    int longestCommonSubstr (string s1, string s2, int n, int m){
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        int maxi = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = 0;
            
                maxi = max(maxi, curr[j]);
            }
            prev = curr;
        }
        
        return maxi;
    }
