class Solution {
    public:
        bool viableCandyCount(vector<int> &candies, long long k, int ncandies) {
            long long nchildserve = 0;
            for(int i = 0; i < candies.size(); i++)
                nchildserve += candies[i]/ncandies; // each location is divided by the number of canies that can be allocated to get the total number of children that can be served
            
            return nchildserve >= k;
        }
    
        int maximumCandies(vector<int>& candies, long long k) {
            long long total_candies = 0;
            int max_candy = INT_MIN;
            for(int c: candies){
                max_candy = max(max_candy, c); // can't give more than max candy to a child
                total_candies += c;
            }
            if(total_candies < k) return 0;
            
            // run a binary search from 0 to max_candy and find the maximum xandy that could be allocated
            int low = 0, high = max_candy;
    
            while(low < high) {
                int mid = (low + high + 1) / 2;
                if(viableCandyCount(candies, k, mid))
                    low = mid;
                else
                    high = mid - 1;
            }
    
            return low;
        }
};