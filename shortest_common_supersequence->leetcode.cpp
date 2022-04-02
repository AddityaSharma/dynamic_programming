class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2){
        // lcs code:
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

        // problem logic:
        string res;        
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                res += s1[i-1];
                i--; j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                res += s1[i-1];
                i--;
            }else{
                res += s2[j-1];
                j--;
            }
        }
        
        while(i > 0){
            res += s1[i-1];
            i--;
        }
        
        while(j > 0){
            res += s2[j-1];
            j--;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};