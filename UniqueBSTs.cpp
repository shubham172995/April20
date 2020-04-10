class Solution {
public:
    int gcd(int a, int b){
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    
    int numTrees(int n) {
        if(n==0)
            return 1;
        long long ans;
        int a, b;
        a=2*n;b=n;
        long long int num=1, den=1;
        while(b){
            num*=a;
            den*=b;
            --a;
            --b;
            int temp=gcd(num, den);
            num/=temp;
            den/=temp;
        }
        ans=num/den;
        ans/=(n+1);
        return ans;
    }
};