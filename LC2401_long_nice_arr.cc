class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int selected_bits = 0;
        int start = 0;
        int maxlen = 1; // individual numbers are nice

        for(int end = 0; end < nums.size(); end++){
            while((selected_bits & nums[end]) != 0){ // remove trailing numbers till nice condition satisfied
                selected_bits ^= nums[start];
                start++;
            }
            selected_bits |= nums[end]; // Use OR to record all set bits
            maxlen = max(end-start + 1, maxlen);
        }

        return maxlen;
    }
};