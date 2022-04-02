// pro-tip:
// tip for myself -> whenever we have to so some changes in string and return count of 
// changes as our answer, at that time, it doesn't necessarily mean that we do the changes and 
// count them, they may be counted even without doing as we have done in this question; both
// word1 and word 2 i.e s and t remains intact -> we just say if we will make that change what
// will be added or subtracted with actually making those changes in our string. -> this small
// observation is the key to solve this question easily.

// recursive code:
int f(int i, int j, string &s, string &t){
    if(i < 0 && j < 0) return 0;
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    
    if(s[i] == t[j]) return f(i-1, j-1, s, t);
    else{
        int insert = 1 + f(i, j-1, s, t);
        int replace = 1 + f(i-1, j-1, s, t);
        int del = 1 + f(i-1, j, s, t);
        return min(insert, min(replace, del));
    }
}

int minDistance(string s, string t){
    int n = s.length();
    int m = t.length();
    return f(n-1, m-1, s, t);
}


// we return i and j here instead of i+1 and j+1 becasue we are not using 1-based-indexing.
// memoization code:
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return 0;
    if(i == 0) return j;
    if(j == 0) return i;
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i-1] == t[j-1]) return dp[i][j] = f(i-1, j-1, s, t, dp);
    else{
        int insert = 1 + f(i, j-1, s, t, dp);
        int replace = 1 + f(i-1, j-1, s, t, dp);
        int del = 1 + f(i-1, j, s, t, dp);
        return dp[i][j] = min(insert, min(replace, del));
    }
}

int minDistance(string s, string t){
    int n = s.length();
    int m = t.length();
    
    // edge case -> if length of any one of s or t is zero.
    if(n == 0) return m;
    if(m == 0) return n;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return f(n, m, s, t, dp);
}


// tabulation code:
int minDistance(string s, string t){
    int n = s.length();
    int m = t.length();
    
    // edge case -> if length of any one of s or t is zero.
    if(n == 0) return m;
    if(m == 0) return n;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int j = 1; j <= m; j++) dp[0][j] = j; // why from 1 ? and not 0. -> consider priority
    for(int i = 1; i <= n; i++) dp[i][0] = i; // why from 1 ? and not 0. -> consider priority
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int insert = 1 + dp[i][j-1];
                int replace = 1 + dp[i-1][j-1];
                int del = 1 + dp[i-1][j];
                dp[i][j] = min(insert, min(replace, del));
            }
        }
    }
    
    return dp[n][m];
}


// => important
// space-optimised code: -> a bit tricky => understand how value of the column in the base case changes and why
// we hvae to cover it inside our indexing loops.
int minDistance(string s, string t){
    int n = s.length();
    int m = t.length();
    
    // edge case -> if length of any one of s or t is zero.
    if(n == 0) return m;
    if(m == 0) return n;
    
    vector<int> prev(m+1, 0), curr(m+1, 0);
    for(int j = 1; j <= m; j++) prev[j] = j; 
    
    for(int i = 1; i <= n; i++){
        curr[0] = i;
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]) curr[j] = prev[j-1];
            else{
                int insert = 1 + curr[j-1];
                int replace = 1 + prev[j-1];
                int del = 1 + prev[j];
                curr[j] = min(insert, min(replace, del));
            }
        }
        prev = curr;
    }
    
    return prev[m];
}
