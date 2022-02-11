#include<bits/stdc++.h>
using namespace std;

/*
// recursive code :
int cal_coin_chainge(vector<int> &coin, int N, int index){
	if(N<0 || index<0) return 0;
	if(N==0) return 1;

	int pick = cal_coin_chainge(coin, N-coin[index], index);
	int not_pick = cal_coin_chainge(coin, N, index-1);

	return pick+not_pick;
}

int main(){
	int N = 3;
	vector<int> coin = {1,2,3,4};
	cout << cal_coin_chainge(coin, N, coin.size()-1) <<endl;
	return 0;
}
*/

/*
// memoization : 
int cal_coin_chainge(vector<int> &coin, int N, int index, vector<vector<int>> &dp){
	if(N<0 || index<0) return 0;
	if(N==0) return 1;
	if(dp[index][N] != -1) return dp[index][N];

	int pick = cal_coin_chainge(coin, N-coin[index], index, dp);
	int not_pick = cal_coin_chainge(coin, N, index-1, dp);

	return dp[index][N] = pick+not_pick;
}

int main(){
	int N = 6;
	vector<int> coin = {1,2,3,4,5};
	vector<vector<int>> dp(coin.size(), vector<int>(N+1, -1));
	cout << cal_coin_chainge(coin, N, coin.size()-1, dp) <<endl;
	return 0;
}
*/
