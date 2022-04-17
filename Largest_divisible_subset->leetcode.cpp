// complete idea is based upon LIS -> specially printing the LIS is the most important task here
// T.C : O(n*n) | S.C : O(n)
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    
    sort(nums.begin(), nums.end());
    int max_len = 1;
    int last_index = 0;
    for(int i = 0; i < n; i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if((nums[i] % nums[prev] == 0) && (1 + dp[prev] > dp[i])){
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if(dp[i] > max_len){
            max_len = dp[i];
            last_index = i;
        }
    }
    
    // creating the required subset:
    vector<int> answer;
    while(hash[last_index] != last_index){
        answer.push_back(nums[last_index]);
        last_index = hash[last_index];
    }
    answer.push_back(nums[last_index]);
    
    return answer;
}
