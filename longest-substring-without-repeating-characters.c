class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0; 
        int maxlen = 0;
        for(int right = 0; right<s.size();right++){
            char current = s[right];
            while(seen.find(current)!=seen.end()){
                seen.erase(s[left]);
                ++left;
            }
            seen.insert(current);
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};