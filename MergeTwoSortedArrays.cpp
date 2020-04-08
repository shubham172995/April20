class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int f=m-1, s=n-1;
        for(int i=n+m-1;i>=0;i--){
            if(s<0)
                break;
            if(f>=0&&nums1[f]>nums2[s]){
                nums1[i]=nums1[f];
                --f;
            }
            else{
                nums1[i]=nums2[s];
                --s;
            }
        }
    }
};