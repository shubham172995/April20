class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a, b, max=INT_MIN;
        a=b=0;
        for(int i=0;i<nums.size();i++){
            max=max>nums[i]?max:nums[i];
            a+=nums[i];
            a=a>0?a:0;
            b=b>a?b:a;
        }
        if(max<b&&b==0)
            return max;
        else return b;
    }
};