class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> pairs;
        for(int n: nums){
            pairs[n]++;
        }


        for(auto p: pairs)
            if((p.second & 1) != 0)
                return false;
        
        return true;
    }
};