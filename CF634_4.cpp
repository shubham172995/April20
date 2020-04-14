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
	while(t--){
		vector<vector<char> > s(9);
		loop(i, 0, 9){
			s[i].resize(9);
			loop(j, 0, 9)
				cin>>s[i][j];
		}
		s[0][1]=s[0][0];
		s[1][4]=s[1][3];
		s[2][7]=s[2][6];
		s[3][0]=s[3][1];
		s[4][3]=s[4][4];
		s[5][6]=s[5][7];
		s[6][2]=s[6][1];
		s[7][5]=s[7][4];
		s[8][8]=s[8][7];
		loop(i, 0, 9){
			loop(j, 0, 9)
				cout<<s[i][j];
			cout<<endl;
		}
	}
	return 0;
}