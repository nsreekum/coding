class Solution {
public:
    bool hasabc(vector<int> &count){
        return (count[0] > 0 && count[1] > 0 && count[2] > 0);
    }

    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int nsstrings = 0;
        vector<int> count(3, 0); // count[a, b, c]

        while(r < n) {
            count[s[r] - 'a']++;
            while(hasabc(count)){ // all three char present in string
                nsstrings += n - r; // number of substrings formed with current string as prefix 

                count[s[l] - 'a']--; // remove first char of current string
                l++;
            }
            r++;
        }

        return nsstrings;
    }
};