#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)

struct comp{
	bool operator()(const int& n1, const int& n2){
		int mod_n1=n1%m;
		int mod_n2=n2%m;
		if (mod_n1 < mod_n2)
            return true;
        else if (mod_n1 == mod_n2)
        {
            if (abs(n1 % 2) == 1)
            {
                if (n2 % 2 == 0)
                    return true;
                // "larger odd number will precede the smaller odd number."
                return n1 > n2;
            }
            else if (n1 % 2 == 0)
            {
                // "smaller even number will precede the larger even number."
                if (n2 % 2 == 0)
                    return n1 < n2;
            }
        }
        return false;
	}
	static int m;
};
int comp::m;

int main(){
	while(1){
		int n;
		cin>>n>>comp::m;
		if(n==0){
			cout<<n<<" "<<comp::m<<endl;
			break;
		}
		vector<int> a(n);
		loop(i, 0, n){
			cin>>a[i];
		}
		cout<<n<<" "<<comp::m<<endl;
		sort(a.begin(), a.end(), comp());
		loop(i, 0, n)
			cout<<a[i]<<endl;
	}
	return 0;
}