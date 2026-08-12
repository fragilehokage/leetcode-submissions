class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, start = -1;
        unordered_map<int,int> m;
        
        for(int end=0;end<nums.size();end++) {
           m[nums[end]]++;
            while (m[nums[end]]>k){
                start++;
                m[nums[start]]--;
            }
            ans = max(ans, end - start);
        }
        
        return ans;
    }
};