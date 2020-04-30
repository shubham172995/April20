class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        if(nums.size()==0){
            ans.push_back(temp);
            return ans;
        }
        int max=pow(2, nums.size())-1;
        int k=0;
        while(k<=max){
            int i=0;
            /*if(k==0){
                temp.push_back(nums[0]);
                ans.push_back(temp);
                temp.clear();
                ++k;
                continue;
            }*/
            int abc=k+1;
            while(k){
                if(k%2==1){
                    temp.push_back(nums[i]);
                }
                k/=2;
                ++i;
            }
            ans.push_back(temp);
            temp.clear();
            k=abc;
        }
        return ans;
    }
};