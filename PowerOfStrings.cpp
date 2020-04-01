int solve(vector<string> &A, string B){
	vector<int> power(26);
	for(int i=0;i<B.length();i++)
		++power[B[i]-'a'];
	vector<int> p(A.size());
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[i].length();j++){
			p[i]+=power[A[i][j]-'a'];
		}
	}
	sort(p.begin(), p.end());
	int ans=INT_MAX;
	for(int i=0;i<p.size()-1;i++){
		ans=abs(p[i]-p[i+1])<ans?abs(p[i]-p[i+1]):ans;
	}
	return ans;
}