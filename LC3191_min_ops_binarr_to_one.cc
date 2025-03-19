class Solution {
public:
    int minOperations(vector<int>& nums) {
        int nflips = 0;
        int sum = 0;

        int n = nums.size();
        for(int i = 2; i < n; i++){
            if(nums[i - 2] == 0){
                nflips++;
                nums[i-2] ^= 1;
                nums[i-1] ^= 1;
                nums[i] ^= 1;
            }
            sum++; // track 1s at i - 2 
        }
        if(nums[n - 2] && nums [n - 1])
            sum += 2;
        
        if(sum == n) return nflips;

        return -1;
    }
};