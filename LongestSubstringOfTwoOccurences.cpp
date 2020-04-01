int solve(string A){
	int ans=0, temp=0;
	bool flag=false;int k=0;
	vector<pair<int, int> > m(256);
	for(int i=0;i<256;i++){
		pair<int, int> p;
		p.first=-1;
		p.second=-1;
		m[i]=p;
	}
	for(int i=0;i<A.length();i++){
		if(flag&&i<k){
			m[A[i]-NULL].first=i;
			m[A[i]-Null].second=-1;
			++temp;
		}
		else if(flag&&i==k){
			flag=false;
			k=0;
			++temp;
			m[A[i]-NULL].second=i;
		}
		else if(m[A[i]-NULL].first==-1){
			++temp;
			m[A[i]-NULL].first=i;
		}
		else{
			if(m[A[i]-NULL].second==-1){
				++temp;
				m[A[i]-NULL].second=i;
			}
			else{
				ans=ans>temp?ans:temp;
				int j=i;
				temp=1;
				m[A[i]-NULL].first=m[A[i]-NULL].first+1;
				m[A[i]-NULL].second=-1;
				flag=true;
				k=i;
				i=m[A[i]-NULL].first;
			}
		}
	}
	ans=ans>temp?ans:temp;
	return ans;
}