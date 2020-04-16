#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	while(1){
		int n;
		scanf("%d", &n);
		if(n==0)
			break;
		int a=0, b=0;
		int i=0;
		bool flag=false;
		while(n){
			int temp=n%2;
			n/=2;
			if(temp==0){
				++i;
				continue;
			}
			if(!flag){
				a+=pow(2, i)*temp;
			}
			else b+=pow(2, i)*temp;
			++i;
			flag=!flag;
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}