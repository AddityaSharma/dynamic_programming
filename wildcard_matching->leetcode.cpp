// recursion code:
bool f(int i, int j, string &pattern, string &text){
    if(i < 0 && j < 0) return 1;
    if(i < 0 && j >= 0) return 0;
    if(j < 0 && i >= 0){
        for(int ii = 0; ii <= i; ii++){
            if(pattern[ii] != '*') return 0;
        }
        return 1;
    }
    
    if(pattern[i] == text[j] || pattern[i] == '?') return f(i-1, j-1, pattern, text);
    if(pattern[i] == '*') return (f(i-1, j, pattern, text) | f(i, j-1, pattern, text));
    
    return 0;
}

bool isMatch(string text, string pattern) {
    int n = pattern.size();
    int m = text.size();
    return f(n-1, m-1, pattern, text);
}


// memoization code:
bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return 1;
    if(i == 0 && j >= 1) return 0;
    if(j == 0 && i >= 1){
        for(int ii = 0; ii <= i-1; ii++){
            if(pattern[ii] != '*') return 0;
        }
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][
    if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') return dp[i][j] = f(i-1, j-1, pattern, text, dp);
    if(pattern[i-1] == '*') return dp[i][j] = (f(i-1, j, pattern, text, dp) | f(i, j-1, pattern, text, dp
    return dp[i][j] = 0;
}

bool isMatch(string text, string pattern) {
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return f(n, m, pattern, text, dp);
}
                                                                                
                                                                                
// tabulation code:
bool isMatch(string text, string pattern) {
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // base cases:
    dp[0][0] == 1;
    for(int j = 1; j<=m; j++) dp[0][j] = 0;
    for(int i = 1; i<=n; i++){
        bool flag = 0;
        for(int ii = 0; ii <= i-1; ii++){
            if(pattern[ii] != '*') { flag = 1; break; }
        }
        if(flag == 0) dp[i][0] = 1;
        else dp[i][0] = 0;
   
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') dp[i][j] =  dp[i-1][j-1];
            else if(pattern[i-1] == '*') dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
            else dp[i][j] = 0;
        }
  
    return dp[n][m];
}
      
      
// space-optimsed code:
bool isMatch(string text, string pattern) {
    int n = pattern.size();
    int m = text.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);
    // base cases:
    prev[0] = 1;
    for(int j = 1; j<=m; j++) prev[j] =
    for(int i = 1; i<=n; i++){
        // logic to fill up the current rows 0th column everytime we move to a new row.
        bool flag = 0;
        for(int ii = 0; ii <= i-1; ii++){
            if(pattern[ii] != '*') { flag = 1; break; }
        }
        if(flag == 0) curr[0] = 1;
        else curr[0] = 0;
        // logic end.
        for(int j = 1; j<=m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') curr[j] =  prev[j-1];
            else if(pattern[i-1] == '*') curr[j] = (prev[j] | curr[j-1]);
            else curr[j] = 0;
        }
        prev = curr;
  
    return prev[m];
}
