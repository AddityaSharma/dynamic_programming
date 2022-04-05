/*
int mod = 1e9 + 7;

// recursive code:
int f(int n){
    if(n == 0) return 1;
    
    int single = f(n-1);
    int paired = 0;
    if(n >= 2) paired = (n-1) * f(n-2);
    
    return (single + paired) % mod;
}

int countFriendsPairings(int n){
    return f(n);
}
*/

long long int mod = 1e9 + 7;

// memoization code:
int f(int n, vector<long long int> &dp){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    
    long long int single = (f(n-1, dp)) % mod;
    long long int paired = 0;
    if(n >= 2) paired = ((n-1) % mod) * (f(n-2, dp) % mod);
    
    return dp[n] = (single + paired) % mod;
}

int countFriendsPairings(int n){
    vector<long long int> dp(n+1, -1);
    return f(n, dp);
}

// tabulation code:
int countFriendsPairings(int n){
    vector<int> dp(n+1, 0);
    // base case:
    dp[0] = 1;
    
    for(int i = 1; i<=n; i++){
        long long int single = (dp[i-1]) % mod;
        long long int paired = 0;
        if(i >= 2) paired = ((i-1) % mod) * (dp[i-2] % mod);
        dp[i] = (single + paired) % mod;
    }
    
    return dp[n];
}

// space-optimised code:
int countFriendsPairings(int n){
    // base case:
    int prev_prev = 0;
    int prev = 1;
    
    for(int i = 1; i<=n; i++){
        long long int single = (prev) % mod;
        long long int paired = 0;
        if(i >= 2) paired = ((i-1) % mod) * (prev_prev % mod);
        int curr = (single + paired) % mod;
        
        prev_prev = prev;
        prev = curr;
    }
    
    return prev;
}
