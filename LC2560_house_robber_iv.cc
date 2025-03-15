class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            int min_reward= 1, max_reward = 0;
            for(int r: nums) max_reward = max(max_reward, r);
            int nhouses = nums.size();
    
            while(min_reward < max_reward) { // O(log m)
                int mid_reward = (min_reward + max_reward) / 2;
                int nthefts = 0;
    
                for(int i = 0; i < nhouses; i++) { // O(n)
                    if(nums[i] <= mid_reward){
                        nthefts += 1;
                        i++; // skip adjacent house
                    }
                }
    
                if(nthefts >= k){
                    max_reward = mid_reward; // there is a chance that there exists a smaller reward/capability
                } else {
                    min_reward = mid_reward + 1; // go for higher rewards as k is not met
                }
    
            } // O(n log m)
    
            return min_reward;
        }
};