#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int b, sg, sb;
		cin>>b>>sg>>sb;
		priority_queue<int> green, blue;
		loop(i, 0, sg){
			int temp;
			cin>>temp;
			green.push(temp);
		}
		loop(i, 0, sb){
			int temp;
			cin>>temp;
			blue.push(temp);
		}
		while(green.size()&&blue.size()){
			int g, b;
			g=green.top();
			b=blue.top();
			green.pop();
			blue.pop();
			if(b==g)
				continue;
			else if(b>g){
				blue.push(b-g);
			}
			else green.push(g-b);
		}
		if(green.size()==0&&blue.size()==0){
			cout<<"green and blue died\n";
		}
		else if(green.size()&&!blue.size()){
			cout<<"green wins\n";
			while(green.size()){
				cout<<green.top()<<endl;
				green.pop();
			}
		}
		else if(blue.size()&&!green.size()){
			cout<<"blue wins\n";
			while(blue.size()){
				cout<<blue.top()<<endl;
				blue.pop();
			}
		}
		if(t)
			cout<<endl;
	}
	return 0;
}