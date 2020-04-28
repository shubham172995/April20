#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int x1, x2, y1, y2;
	cin>>x1>>y1>>x2>>y2;
	map<pair<int, int>, bool> m;
	/*if(x1==y1||((x1!=0&&y1==0)||(x1==0&&y1!=0))){
		if(x2==y2||((x2!=0&&y2==0)||(x2==0&&y2!=0))){
			m[pair<int, int>(x1, y1)]=1;
			m[pair<int, int>(x2, y2)]=1;
		}
		else{
			cout<<"-1\n"''
		}
	}
	else if(x1==x2&&y1==y2){
		cout<<"-1\n";
	}
	else{
		cout<<"-1\n";
	}*/
	if(x1==x2||y1==y2||(abs(x1-x2)==abs(y1-y2))){
		if(abs(x1-x2)==abs(y1-y2)){
			cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
		}
		else if(x1==x2){
			cout<<x1+y1-y2<<" "<<y1<<" "<<x1+y1-y2<<" "<<y2<<endl;
		}
		else{
			cout<<x1<<" "<<y1+x1-x2<<" "<<x2<<" "<<y1+x1-x2<<endl;
		}
	}
	else{
		cout<<"-1\n";
	}
	return 0;
}