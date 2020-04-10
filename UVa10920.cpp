#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int sz, p;
	while(1){
		cin>>sz>>p;
		if(sz==0)
			break;
		int temp=0;
		loop(i, 1, sz+1){
			temp=pow(i, 2);
			if(temp>=p){
				temp=i;
				break;
			}
		}
		if(temp%2==0)
			++temp;
		int rmid, colmid;
		rmid=colmid=(sz/2)+1;
		int row=rmid+(temp-1)/2;
		int col=colmid+(temp-1)/2;
		int val=temp*temp;
		bool flag=false;
		//cout<<val<<" "<<row<<" "<<col<<" "<<colmid<<" "<<rmid<<endl;
		if(val==p){
			cout<<"Line = "<<row<<", column = "<<col<<".\n";
			continue;
		}
		else{
			for(int i=0;i<temp;i++){
				if(val==p){
					cout<<"Line = "<<row<<", column = "<<col<<".\n";
					flag=true;
					break;
				}
				--val;
				--row;
				//cout<<val<<" "<<row<<" "<<col<<endl;
			}
			if(flag)
				continue;
			++val;
			++row;
			for(int i=0;i<temp;i++){
				if(val==p){
					cout<<"Line = "<<row<<", column = "<<col<<".\n";
					flag=true;
					break;
				}
				--val;
				--col;
				//cout<<val<<" "<<row<<" "<<col<<endl;
			}
			if(flag)
				continue;
			++val;
			++col;
			for(int i=0;i<temp;i++){
				if(val==p){
					cout<<"Line = "<<row<<", column = "<<col<<".\n";
					flag=true;
					break;
				}
				--val;
				++row;
				//cout<<val<<" "<<row<<" "<<col<<endl;
			}
			if(flag)
				continue;
			++val;
			--row;
			for(int i=0;i<temp;i++){
				if(val==p){
					cout<<"Line = "<<row<<", column = "<<col<<".\n";
					flag=true;
					break;
				}
				--val;
				++col;
				//cout<<val<<" "<<row<<" "<<col<<endl;
			}
			if(flag)
				continue;
		}
	}
	return 0;
}