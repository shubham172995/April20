#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int n;
	while(cin>>n){
		vector<int> weight;
		loop(i, 0, 1<<n){
			int temp;
			cin>>temp;
			weight.pb(temp);
		}
		vector<int> potencies;
		loop(i, 0, 1<<n){
			int temp=0;
			loop(j, 0, n)
				temp+=weight[i^(1<<j)];
			potencies.pb(temp);
		}
		int maxi=0;
		loop(i, 0, 1<<n){
			loop(j, 0, n){
				maxi=max(maxi, potencies[i]+potencies[i^(1<<j)]);
			}
		}
		cout<<maxi<<endl;
	}
	return 0;
}