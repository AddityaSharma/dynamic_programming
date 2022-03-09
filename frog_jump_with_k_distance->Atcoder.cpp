
// problem -> frog jump with k distance.

/*
// recursive code:
int f(int n, int k, int height[]){
	if(n==0) return 0;

	int minV = INT_MAX;
	for(int i = 1; i<=k; i++){
		if(n-i>=0) minV = min(minV, (abs(height[n]-height[n-i]) + f(n-i, k, height)));
	}

	return minV;
}

int main(){
	int n, k;
	cin >> n >> k;
	int height[n];
	for(int i=0; i<n; i++) cin >> height[i];

	cout << f(n-1, k , height) << endl;
	return 0;
}
*/

/*
// memoization code:
int f(int n, int k, int height[], int dp[]){
	if(n==0) return 0;
	if(dp[n] != -1) return dp[n];

	int minV = INT_MAX;
	for(int i = 1; i<=k; i++){
		if(n-i>=0) minV = min(minV, (abs(height[n]-height[n-i]) + f(n-i, k, height, dp)));
	}

	return dp[n] = minV;	
}

int main(){
	int n, k;
	cin >> n >> k;
	int height[n];
	for(int i=0; i<n; i++) cin >> height[i];

	int dp[n];
	for(int i=0; i<n; i++) dp[i] = -1;
	cout << f(n-1, k , height, dp) << endl;
	return 0;
}
*/

/*
// tabulation code:
int main(){
	int N, k;
	cin >> N >> k;
	int height[N];
	for(int i=0; i<N; i++) cin >> height[i];
	// driver code ends

	int dp[N] = { 0 };
	dp[0] = 0;

	for(int n = 1; n < N; n++){
		int minV = INT_MAX;
		for(int i = 1; i <= k; i++){
			if(n-i>=0) minV = min(minV, (abs(height[n]-height[n-i]) + dp[n-i]));
		}
		dp[n] = minV;
	}

	cout << dp[N-1] << endl;
	return 0;
}
*/
