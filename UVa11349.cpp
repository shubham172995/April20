#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)

int main(){
	int t;
	scanf("%d", &t);
	loop(te, 1, t+1){
		getchar();
		string ans="";
		string str;
		getline(cin, str);
		str=str.substr(4, str.length()-4);
		int n=0;
		loop(i, 0, str.length()){
			n=n*10+(str[i]-'0');
		}
		bool flag=false;
		vector<vector<ll> > m(n);
		loop(i, 0, n){
			m[i].resize(n);
			loop(j, 0, n){
				cin>>m[i][j];
				if(m[i][j]<0)
					flag=true;
			}
		}
		if(flag){
			ans="Non-symmetric.";
			cout<<"Test #"<<te<<": "<<ans<<endl;
			continue;
		}
		loop(i, 0, n){
			loop(j, 0, n){
				if(i+j>=n)
					break;
				int im, jm, temp=n/2;
				im=temp+temp-i-(n%2==0?1:0);
				jm=temp+temp-j-(n%2==0?1:0);
				//cout<<i<<" "<<j<<" "<<im<<" "<<jm<<endl;
				if(m[i][j]!=m[im][jm]){
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			ans="Non-symmetric.";
		else ans="Symmetric.";
		cout<<"Test #"<<te<<": "<<ans<<endl;
	}
	return 0;
}