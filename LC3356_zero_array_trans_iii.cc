class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);

        int psum = 0, k = 0;
        for(int i = 0; i < n; i++){
            //go through all queries till nums[i] not zero
            while(psum + diff[i] < nums[i]){
                k++;
                if(k > queries.size()) return -1;

                int l = queries[k - 1][0];
                int r = queries[k - 1][1];
                int val = queries[k - 1][2];

                if(r >= i){
                    diff[max(l, i)] += val;
                    diff[r + 1] -= val;
                }
            }

            psum += diff[i];
        }

        return k;
    }
};
/*
arr             - [1, 5, 8, 10, 11]
diff            - [1, 4, 3, 2, 1]
range update +2 - [1, 6, 3, 2, -1] [1, 3, 2]

[1, 7, 10, 12, 11]
    |           |
    effect of   |
    +2 start    |
                effect of 
                +2 negated
*/