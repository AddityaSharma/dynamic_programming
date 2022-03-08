class Solution {
public:
    /*
    // recursive code:
    int f(int index1, int index2, string s1, string s2){
        if(index1 < 0 || index2 < 0) return 0;
        
        if(s1[index1] == s2[index2]) return 1 + f(index1-1, index2-1, s1, s2);
        return max(f(index1-1, index2, s1, s2),f(index1, index2-1, s1, s2));
    }
    
    int longestCommonSubsequence(string s1, string s2){
        return f(s1.length()-1, s2.length()-1, s1, s2);
    }
    */
    
    // used the concept of shifting of index in the folling memoization, tabulation and
    // space-optimsied code, if any doubt refer Dp-26(Tuf).
    
    /*
    // memoization code:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        return dp[i][j] = max(f(i-1, j, s1, s2, dp),f(i, j-1, s1, s2, dp));
    }
    
    int longestCommonSubsequence(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n, m, s1, s2, dp);
    }
    */
    
    /*
    // tabulation code:
    int longestCommonSubsequence(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        for(int j = 0; j<=m; j++) dp[0][j] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    
        return dp[n][m];
    }
    */
    
    // space-optimised code:
    int longestCommonSubsequence(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        vector<int> dp(m+1, 0), temp(m+1, 0);
        
        for(int i = 0; i<=n; i++) dp[0] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) temp[j] = 1 + dp[j-1];
                else temp[j] = max(dp[j], temp[j-1]);
            }
            dp = temp;
        }
    
        return dp[m];
    }
};
