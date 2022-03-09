class Solution {
public:
    // space-optmised house-robber-1 code -> with minor chnages with range of nums:
    int rob(vector<int>& nums, int l ,int r) {
        int prev1 = nums[l];
        int prev2 = 0;
        for(int i = l+1; i<r; i++){
            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
    }
};
