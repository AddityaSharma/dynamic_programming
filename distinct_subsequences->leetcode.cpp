
// recursive code:
int f(int i, int j, string s, string t){
    if(j < 0) return 1;
    if(i < 0) return 0;
    
    if(s[i] == t[j]) return f(i-1, j-1, s, t) + f(i-1, j, s, t);
    return f(i-1, j, s, t);
}

int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    return f(n-1, m-1, s, t);
}


// memoization code: -> 1-based indexing approach
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(j == 0) return 1;
    if(i == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i-1] == t[j-1]) return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
    return dp[i][j] = f(i-1, j, s, t, dp);
}

int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return f(n, m, s, t, dp);
}


// tabulation code:    
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
    
    // base case:
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int j = 1; j <= m; j++) dp[0][j] = 0; // understand why j is starting from 1 not 0.
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    return (int)dp[n][m];
}


// space-optimised code: -> two array space optimisation
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<double> dp(m+1, 0);
    
    // base case:
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        vector<double> temp(m+1, 0);
        temp[0] = 1; 
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]) temp[j] = dp[j-1] + dp[j];
            else temp[j] = dp[j];
        }
        dp = temp;
    }
    
    return (int)dp[m];
}


// space-optimised code: -> one array space optimisation
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<double> dp(m+1, 0);
    
    // base case:
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = m; j > 0; j--){
            if(s[i-1] == t[j-1]) dp[j] = dp[j-1] + dp[j];
        }
    }
    
    return (int)dp[m];
}
