class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, bool> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=1;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i]+1)!=m.end())
                ++ans;
        }
        return ans;
    }
};