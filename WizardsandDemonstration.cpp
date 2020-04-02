#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	ll people=y*n;
	float temp=people+0.0;
	people=ceil(temp/100);
	//cout<<people<<endl;
	cout<<(people>x?people-x:0)<<endl;
	return 0;
}