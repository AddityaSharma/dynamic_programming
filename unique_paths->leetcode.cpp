#include <bits/stdc++.h>
using namespace std;

/*
    // recursion code:
    int paths(int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        int u = paths(i-1, j);
        int l = paths(i, j-1);
        return u + l;
    }
    
    int uniquePaths(int m, int n) {
        return paths(m-1, n-1);
    }
    */
    
    /*
    // memoization code:
    int paths(int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int u = paths(i-1, j, dp);
        int l = paths(i, j-1, dp);
        
        return dp[i][j] = u + l;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector <int> (n, -1));
        return paths(m-1, n-1, dp);
    }
    */
    
    /*
    // tabulation:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector <int> (n, -1));
        dp[0][0] = 1;
        
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j==0) continue;
                int l = 0, u = 0;
                if(i>0) u = dp[i-1][j];
                if(j>0) l = dp[i][j-1];
                dp[i][j] = u + l;
            }
        }
        return dp[m-1][n-1];
    }
    */
    
    // space optimization:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        
        for(int i=0; i<m; i++){
            vector<int> temp(n, 0);
            for(int j = 0; j<n; j++){
                if(i == 0 && j==0){ 
                    temp[j] = 1; 
                    continue; 
                } 
                int l = 0, u = 0;
                if(i>0) u = dp[j];
                if(j>0) l = temp[j-1];
                temp[j] = u + l;
            }
            dp = temp;
        }
        return dp[n-1];
    }
