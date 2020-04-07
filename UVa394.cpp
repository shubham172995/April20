#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int n, m;
	cin>>n>>m;
	map<string, int> ma;
	vector<int> B(n), D(n);
	vector<vector<int> > L(n), U(n), C(n);
	loop(i, 0, n){
		string str;
		cin>>str;
		ma[str]=i;
		int temp;
		cin>>B[i]>>temp>>D[i];
		L[i].resize(D[i]+1);
		U[i].resize(D[i]+1);
		C[i].resize(D[i]+1);
		C[i][D[i]]=temp;
		loop(j, 1, D[i]+1){
			int a, b;
			cin>>a>>b;
			L[i][j]=a;
			U[i][j]=b;
		}
	}
	loop(i, 0, n){
		for(int j=D[i]-1;j>0;j--){
			C[i][j]=C[i][j+1]*(U[i][j+1]-L[i][j+1]+1);
		}
		C[i][0]=B[i];
		loop(j, 1, D[i]+1){
			C[i][0]-=C[i][j]*L[i][j];
		}
	}
	loop(i, 0, m){
		string str;
		cin>>str;
		//cout<<ma[str]<<" "<<D[ma[str]]<<" "<<B[ma[str]]<<endl;
		cout<<str<<"[";
		int d=D[ma[str]];
		int ans=C[ma[str]][0];
		loop(j, 1, d+1){
			int k;
			cin>>k;
			ans+=k*C[ma[str]][j];
			if(j<d)
				cout<<k<<", ";
			else cout<<k<<"] = ";
		}
		cout<<ans<<endl;
	}
	return 0;
}