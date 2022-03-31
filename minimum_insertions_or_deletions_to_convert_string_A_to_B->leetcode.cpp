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

int minDistance(string s1, string s2) {
  int lcs = longestCommonSubsequence(s1, s2);
  return (s1.length() - lcs) + (s2.length() - lcs);
}
