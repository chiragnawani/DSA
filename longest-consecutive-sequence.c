class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        if(size ==0){
            return 0;
        }
        int curlen = 1;
        int globallen = 0;
        for(int i = 1; i<size; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i]-1 == nums[i-1]){
                curlen++;
            }
            else{
                globallen = max(curlen,globallen);
                curlen = 1;
            }
        }
        int m = max(curlen,globallen);
    return m;
    }
};