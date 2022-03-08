#include<bits/stdc++.h>
using namespace std;

// print longest common subsequence:

/*
// method-1 : striver(Tuf) -> build upon the concept of Longest Common Subsequence:
string longestCommonSubsequence(string s1, string s2){
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
    
    // we use the dp array created during the length of LCS question to extract the longest common subsequence string.
    int len = dp[n][m];
    string ans = "";
    for(int i = 0; i<len; i++) ans += "$";

    int index = len-1;
	int i = n, j = m;
	while(i>0 && j>0){
		if(s1[i-1] == s2[j-1]){
			ans[index] = s1[i-1];
			index--;
			i--; j--;
		}else if(dp[i-1][j] > dp[i][j-1]) i = i-1;
		else j = j-1;
	}
	
	return ans;
}


int main(){
	string s1, s2;
	cin >> s1 >> s2;

	cout << longestCommonSubsequence(s1, s2) << endl;
	return 0;
}
*/



// method-2 : my personal approach to solve this question:
/*
// recursion code:
string f(int i, int j, string s1, string s2){
	if(i < 0 || j < 0) return "";

	if(s1[i] == s2[j]) return f(i-1, j-1, s1, s2) + s1[i];

	string t1 = f(i-1, j, s1, s2);
	string t2 = f(i, j-1, s1, s2);
 
	if(t1.length() > t2.length()) return t1;
	else return t2;  
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;

	cout << f(s1.length()-1, s2.length()-1, s1, s2) << endl;
	return 0;
}
*/

/*
// memoization code:
string f(int i, int j, string &s1, string &s2, vector<vector<string>> &dp){
	if(i == 0 || j == 0) return "";
	if(dp[i][j] != "$") return dp[i][j];

	if(s1[i-1] == s2[j-1]) return dp[i][j] = f(i-1, j-1, s1, s2, dp) + s1[i-1];

	string t1 = f(i-1, j, s1, s2, dp);
	string t2 = f(i, j-1, s1, s2, dp);
 
	if(t1.length() > t2.length()) return dp[i][j] = t1;
	else return dp[i][j] = t2;  
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();

	vector<vector<string>> dp(n+1, vector<string>(m+1, "$"));
	cout << f(n, m, s1, s2, dp) << endl;
	return 0;
}
*/

/*
// tabulation code:
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();

	vector<vector<string>> dp(n+1, vector<string>(m+1, "$"));
	for(int i = 0 ;i <= n; i++)dp[i][0] = "";
	for(int j = 0 ;j <= m; j++)dp[0][j] = "";

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + s1[i-1];
			else{
				string t1 = dp[i-1][j];
				string t2 = dp[i][j-1];
				if(t1.length() > t2.length()) dp[i][j] = t1;
				else dp[i][j] = t2;
			}  
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
*/

/*
// space-optimsed code:
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();

	vector<string> curr(m+1, "$"), prev(m+1, "$");
	prev[0] = "";
	for(int j = 0 ;j <= m; j++)prev[j] = "";

	for(int i=1; i<=n; i++){
		curr[0] = "";
		for(int j=1; j<=m; j++){
			if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1] + s1[i-1];
			else{
				string t1 = prev[j];
				string t2 = curr[j-1];
				if(t1.length() > t2.length()) curr[j] = t1;
				else curr[j] = t2;
			}  
		}
		prev = curr;
	}
	cout << prev[m] << endl;
	return 0;
}
*/
