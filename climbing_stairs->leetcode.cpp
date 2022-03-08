class Solution {
public:
    /*
    // memoization method : 
    int calculate_steps(int n, vector<int> &dp){
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = calculate_steps(n-1, dp) + calculate_steps(n-2, dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return calculate_steps(n, dp);
    }
    */
    
    /*
    // tabulation :
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    */
    
    /*
    // space optimisation :
    int climbStairs(int n){
        int prev1 = 1;
        int prev2 = 1;
        for(int i = 2; i<=n; i++){
            int curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    } 
    */
};
