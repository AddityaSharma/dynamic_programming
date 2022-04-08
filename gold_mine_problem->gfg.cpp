
// recursive solution:
int f(int i, int j, vector<vector<int>> &mat){
    if(j == 0) return mat[i][j];
    
    int dia_up = 0;
    int left = 0;
    int dia_down = 0;
    
    if(i > 0 && j > 0) dia_up = mat[i][j] + f(i-1, j-1, mat);
    if(j > 0) left = mat[i][j] + f(i, j-1, mat);
    if(i < mat.size()-1 && j > 0) dia_down = mat[i][j] + f(i+1, j-1, mat);
    
    return max(left, max(dia_up, dia_down));
}

int maxGold(int n, int m, vector<vector<int>> mat){
    int max_gold = 0;
    for(int i = 0; i < n; i++){
        max_gold = max(max_gold, f(i, m-1, mat));
    }
    return max_gold;
}
    
    

// memoization solution:
int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(j == 0) return mat[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    
    int dia_up = 0;
    int left = 0;
    int dia_down = 0;
    
    if(i > 0 && j > 0) dia_up = mat[i][j] + f(i-1, j-1, mat, dp);
    if(j > 0) left = mat[i][j] + f(i, j-1, mat, dp);
    if(i < mat.size()-1 && j > 0) dia_down = mat[i][j] + f(i+1, j-1, mat, dp);
    
    return dp[i][j] = max(left, max(dia_up, dia_down));
}

int maxGold(int n, int m, vector<vector<int>> mat){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int max_gold = 0;
    for(int i = 0; i < n; i++){
        max_gold = max(max_gold, f(i, m-1, mat, dp));
    }
    return max_gold;
}
    
    
// tabulation solution:
int maxGold(int n, int m, vector<vector<int>> mat){
     vector<vector<int>> dp(n, vector<int>(m, 0));
     // base case:
     for(int i = 0; i<n; i++) dp[i][0] = mat[i][0];
     
     for(int i = 0; i < n; i++){
         for(int j = 1; j < m; j++){
             int dia_up = 0;
             int left = 0;
             int dia_down = 0;
             
             if(i > 0 && j > 0) dia_up = mat[i][j] + dp[i-1][j-1];
             if(j > 0) left = mat[i][j] + dp[i][j-1];
             if(i < mat.size()-1 && j > 0) dia_down = mat[i][j] + dp[i+1][j-1];
             dp[i][j] = max(left, max(dia_up, dia_down));
         }
     }
 
     int max_gold = 0;
     for(int i = 0; i < n; i++){
         max_gold = max(max_gold, dp[i][m-1]);
     }
     return max_gold;
 }
