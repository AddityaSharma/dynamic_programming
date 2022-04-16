class Solution {
public:
    // recursive code:
    T.C : exponential | S.C : O(n)
    int f(int index, int prev_ind, vector<int> &nums){
        if(index == nums.size()) return 0;
        
        int len = f(index+1, prev_ind, nums); // not_take case
        if(prev_ind == -1 || nums[index] > nums[prev_ind]) {
            len = max(len, 1 + f(index+1, index, nums)); // take case
        }
        return len;
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return f(0, -1, nums);
    }
    
    
    // memoization solution -> used the concept of co-ordinate change -> TLE
    // T.C : O(n*n) | S.C : O(n*n) + O(n)
    int f(int index, int prev_ind, vector<int> &nums, vector<vector<int>> &dp){
        if(index == nums.size()) return 0;
        if(dp[index][prev_ind+1] != -1) return dp[index][prev_ind+1];
        
        int len = f(index+1, prev_ind, nums, dp); // not_take case
        if(prev_ind == -1 || nums[index] > nums[prev_ind]) {
            len = max(len, 1 + f(index+1, index, nums, dp)); // take case
        }
        return dp[index][prev_ind+1] = len;
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
    
    
    // tabulation solution -> used the concept of co-ordinate change -> just enough to prevent TLE
    // co-oordinate change is a really important concept to understand here.
    // T.C : O(n*n) | S.C : O(n*n)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int index = n-1; index >= 0; index--){
            for(int prev_ind = index - 1; prev_ind >= -1; prev_ind--){
                int len = dp[index+1][prev_ind+1]; // not_take case
                if(prev_ind == -1 || nums[index] > nums[prev_ind]) {
                    len = max(len, 1 + dp[index+1][index+1]); // take case
                }
                dp[index][prev_ind+1] = len;
            }
        }
        return dp[0][-1+1];
    }
    
    
    // space-optimised solution -> used the concept of co-ordinate change
    // co-oordinate change is a really important concept to understand here.
    // T.C : O(n*n) | S.C : O(n)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+1, 0), curr(n+1, 0);
        
        for(int index = n-1; index >= 0; index--){
            for(int prev_ind = index - 1; prev_ind >= -1; prev_ind--){
                int len = next[prev_ind+1]; // not_take case
                if(prev_ind == -1 || nums[index] > nums[prev_ind]) {
                    len = max(len, 1 + next[index+1]); // take case
                }
                curr[prev_ind+1] = len;
            }
            next = curr;
        }
        return next[-1+1];
    }
    
    
    // a unique way of doing this question -> takeuforward
    // in dp vector, at every index i, we are storing maximum length of LIS which can be formed.
    // T.C : O(n*n) | S.C : O(n)
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int max_lis = 1;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            max_lis = max(max_lis, dp[i]);
        }
        
        return max_lis;
    }
    
    
    // printing LIS -> can be done only using the above function method
    // T.C : O(n*n) | S.C : O(n)
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        
        int max_lis = 1;
        int last_index = 0;
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){  // very important - (1 + dp[prev] > dp[i]) 
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > max_lis){
                max_lis = dp[i];
                last_index = i;
            }
        }
        
        vector<int> lis;
        while(hash[last_index] != last_index){
            lis.push_back(nums[last_index]);
            last_index = hash[last_index];
        }
        lis.push_back(nums[last_index]);
        
        reverse(lis.begin(), lis.end());
        
        for(int i = 0; i < lis.size(); i++) cout << lis[i] << " ";
        cout << endl;
        
        return max_lis;
    }
    
    
    // binary search: -> best approach -> will work if n = 1e5, where all other approaches will give TLE.
    // T.C : O(nlogn) | S.C : O(n)
    int lengthOfLIS(vector<int>& nums){
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > temp.back()) temp.push_back(nums[i]);
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};
