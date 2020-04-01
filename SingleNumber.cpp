class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                ans = nums[i];
                break;
            }
            else ++i;
        }
        if(ans==INT_MIN)
            ans=nums[nums.size()-1];
        return ans;
    }
};