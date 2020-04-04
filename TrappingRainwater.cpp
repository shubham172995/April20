class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        stack<int> s;
        int ans=0, max=height[0];
        s.push(height[0]);
        for(int i=1;i<height.size();i++){
            if(height[i]<=max){
                s.push(height[i]);
                max=max>height[i]?max:height[i];
            }
            else{
                for(int j=i;j<height.size();j++){
                    if(height[j]>max)
                        break;
                    s.push(height[j]);
                    i=j;
                }
                while(s.size()){
                    if(s.top()>height[i]){
                        s.pop();
                        continue;
                    }
                    //cout<<"Hey "<<i<<" "<<max<<" "<<max-s.top()<<" "<<height[i]-s.top()<<endl;
                    int temp=max<height[i]?(max-s.top()):(height[i]-s.top());
                    ans+=temp>0?temp:0;
                    s.pop();
                    //cout<<ans<<endl;
                }
                s.push(height[i]);
                max=height[i];
                //cout<<i<<" oye "<<max<<endl;
            }
            //cout<<s.top()<<" "<<max<<" "<<ans<<endl;
        }
        max=-1;
        while(s.size()){
            if(max<s.top()){
                max=s.top();
                s.pop();
            }
            else{
                ans+=max-s.top();
                s.pop();
            }
        }
        return ans;
    }
};