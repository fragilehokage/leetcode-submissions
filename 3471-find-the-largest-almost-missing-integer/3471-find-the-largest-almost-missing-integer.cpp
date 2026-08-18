class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){//1st case
             return *max_element(nums.begin(), nums.end());
        }
        //2nd case
        unordered_map<int,int>m;
        for(int x:nums){
            m[x]++;
        }
         if(k==1){
            int maxi=-1;
            for(auto mi :m){
                int first=mi.first;
                int count=mi.second;
                if(count==1){
                    maxi=max(maxi,first);
                }
            }
            return maxi;
         }

         int maxi=-1;

         if(m[nums[0]]==1 || m[nums[n-1]]==1){
            if(m[nums[0]]==1){
                maxi=max(maxi,nums[0]);
            }
            if (m[nums[n - 1]] == 1) {
                maxi = max(maxi, nums[n - 1]);
            }
         }
         return maxi;
    }
};