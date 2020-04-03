class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;
        m[n]=1;
        if(n==1)
            return 1;
        while(1){
            int temp=0;
            while(n){
                temp+=(n%10)*(n%10);
                n/=10;
            }
            n=temp;
            if(m.find(n)==m.end()){
                m[n]=1;
            }
            else
                break;
            if(n==1)
                return 1;
        }
        return 0;
    }
};