class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        map<int, int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]=2;
            }
            else m[nums[i]]=1;
        }
        for(int i=0;i<nums.size();i++){
            //cout<<m[nums[i]]<<" ";
            if(m[nums[i]]==1){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};