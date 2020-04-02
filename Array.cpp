#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	loop(i, 0, n){
		cin>>a[i];
	}
	vector<int> ne, p, z;
	loop(i, 0, n){
		if(a[i]<0)
			ne.push_back(a[i]);
		else if(a[i]>0)
			p.push_back(a[i]);
		else if(a[i]==0)
			z.push_back(a[i]);
	}
	if(ne.size()%2==0){
		int temp=ne[0];
		ne.erase(ne.begin()+0);
		z.push_back(temp);
	}
	if(p.size()==0){
		int t1, t2;
		t1=ne[0];
		t2=ne[1];
		ne.erase(ne.begin()+0);
		ne.erase(ne.begin()+0);
		p.push_back(t1);
		p.push_back(t2);
	}
	cout<<ne.size()<<" ";
	loop(i, 0, ne.size())
		cout<<ne[i]<<" ";
	cout<<endl<<p.size()<<" ";
	loop(i, 0, p.size())
		cout<<p[i]<<" ";
	cout<<endl<<z.size()<<" ";
	loop(i, 0, z.size())
		cout<<z[i]<<" ";
	cout<<endl;
	return 0;
}