class Solution {
public:
    int binSearchZero(vector<int> &nums, int low, int high) {
        if(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > 0){
                return binSearchZero(nums, low, mid);
            } else {
                if( mid + 1 < nums.size()){
                    if(nums[mid + 1] > 0)
                        return mid;
                    return binSearchZero(nums, mid, high);
                }
                return nums.size() - 1;
            }
        }
        return -1;
    }

    int binSearchNeg(vector<int> &nums, int low, int high) {
        if(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < 0){
                if(mid + 1 < nums.size()){
                    if (nums[mid + 1] >= 0)
                        return mid;
                    return binSearchNeg(nums, mid, high);
                }
                return nums.size() - 1;
            } else {
                return binSearchNeg(nums, low, mid);
            }
        }
        return -1;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] > 0 || nums[n - 1] < 0)
            return nums.size();
        int neg_loc = binSearchNeg(nums, 0, n);
        if(neg_loc + 1 < n){
            if(nums[neg_loc + 1] > 0)
                return max(neg_loc + 1, n - neg_loc - 1);
        }else{ 
            return neg_loc + 1;
        }
        int zero_loc = binSearchZero(nums, neg_loc + 1, n);
        if(zero_loc + 1 >= n){
            return neg_loc + 1;
        }
        // cout << neg_loc << " " << zero_loc << endl;
        return max(neg_loc + 1, n - zero_loc - 1);
    }
};