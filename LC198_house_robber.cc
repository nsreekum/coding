class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            vector<int> max_rob(n, 0); // memoization
            max_rob[0] = nums[0];
            max_rob[1] = max(nums[0], nums[1]);
            for(int i = 2; i < n; i++) // prev location or current + prev location
                max_rob[i] = max(max_rob[i-1], max_rob[i-2] + nums[i]);
            // O(n)
            return max_rob[n-1];
        }
};