// LCS based solution:

// reverse function:
void reverseStr(string& str){
  int n = str.length();
  for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
}

// code from LCS:
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

int longestPalindromeSubseq(string s) {
  string str = s;
  reverseStr(s);
  return longestCommonSubsequence(s, str);
}
    
