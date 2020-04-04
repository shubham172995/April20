#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int t;
	cin>>t;
	for(int x=1;x<=t;x++){
		int n;
		int k=0;
		cin>>n;
		vector<vector<int> > a(n), r(n), c(n);
		loop(i, 0, n){
			r[i].resize(101);
			c[i].resize(101);
		}
		loop(i, 0, n){
			a[i].resize(n);
			loop(j, 0, n){
				cin>>a[i][j];
				if(i==j)
					k+=a[i][j];
				++r[i][a[i][j]];
				++c[j][a[i][j]];
			}
		}
		cout<<"Case #"<<x<<": "<<k<<" ";
		int rows=0, cols=0;
		loop(i, 0, n){
			loop(j, 0, 101){
				if(r[i][j]>1){
					++rows;
					break;
				}
			}
		}
		loop(i, 0, n){
			loop(j, 0, 101){
				if(c[i][j]>1){
					++cols;
					break;
				}
			}
		}
		cout<<rows<<" "<<cols<<endl;
	}
	return 0;
}