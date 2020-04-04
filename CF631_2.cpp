#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

const int SIZE=200000;
vector<int> p(SIZE);
int res[SIZE][2];
int r;

bool unique(vector<int>& a, int len, int i){
	static vector<bool> freq(SIZE+1);
	loop(j, 0, len+1)freq[j]=0;
	loop(j, i, len)freq[a[j]]=1;
	loop(j, 1, len+1-i)
		if(!freq[j])
			return 0;
	return 1;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		r=0;
		int n;
		scanf("%d", &n);
		int m=0;
		loop(i, 0, n){
			scanf("%d", &p[i]);
			m=m>p[i]?m:p[i];
		}
		//cout<<m<<endl;
		if(unique(p, m, 0)&&unique(p, n, m)){
			res[r][0]=m;
			res[r++][1]=n-m;
			//cout<<"HEY "<<res[0][0]<<" "<<res[0][1]<<endl;
		}
		if(m*2!=n){
			if(unique(p, n-m, 0)&&unique(p, n, n-m)){
				res[r][0]=n-m;
				res[r++][1]=m;
				//cout<<"OKAY\n";
			}
		}
		cout<<r<<endl;
		loop(i, 0, r){
			cout<<res[i][0]<<" "<<res[i][1]<<endl;
		}
	}
	return 0;
}